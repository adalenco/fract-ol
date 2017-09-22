#include "fractol.h"
#include "get_next_line.h"
#include <stdio.h>

void        ft_cpykernel(t_ws *prm, int fd)
{
    int     ret;
    char    *line;
    char    *tmp;

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        tmp = prm->KernelSource;
        prm->KernelSource = ft_strjoin(prm->KernelSource, "\n");
        tmp = prm->KernelSource;
        prm->KernelSource = ft_strjoin(prm->KernelSource, line);
        free(tmp);
        free(line);
    }
    if (ret == -1)
    {
        printf("getnextline error\n");
        exit(1);
    }
    tmp = prm->KernelSource;
    prm->KernelSource = ft_strjoin(prm->KernelSource, "\n");
    free(tmp);
    close(fd);
}

void        ft_loadkernel(t_ws *prm)
{
    int     fd;

    if ((prm->KernelSource = ft_strdup("#define FROM_KERNEL\n")) == NULL)
    {
        printf("malloc error while loading kernel\n");
        exit(1);
    }
    if ((fd = open("./src/fractol.cl", O_RDONLY)) == -1)
    {
        printf("error while openning kernel\n");
        exit(1);
    }
    ft_cpykernel(prm, fd);
}

int         ft_opencl_init(t_ws *prm)
{
    int     gpu;
    int     err;

    gpu = 1;
    ft_loadkernel(prm);
    err = clGetDeviceIDs(NULL, gpu ? CL_DEVICE_TYPE_GPU : CL_DEVICE_TYPE_CPU, 1, &prm->device_id, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
    prm->context = clCreateContext(0, 1, &prm->device_id, NULL, NULL, &err);
    if (!prm->context)
    {
        printf("Error: Failed to create a compute context!\n");
        return EXIT_FAILURE;
    }
    prm->commands = clCreateCommandQueue(prm->context, prm->device_id, 0, &err);
    if (!prm->commands)
    {
        printf("Error: Failed to create a command commands!\n");
        return EXIT_FAILURE;
    }
    prm->program = clCreateProgramWithSource(prm->context, 1, (const char **) & prm->KernelSource, NULL, &err);
    if (!prm->program)
    {
        printf("Error: Failed to create compute program!\n");
        return EXIT_FAILURE;
    }
    err = clBuildProgram(prm->program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        size_t len;
        char buffer[50000];

        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(prm->program, prm->device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        exit(1);
    }
    prm->kernel = clCreateKernel(prm->program, "fractal", &err);
    if (!prm->kernel || err != CL_SUCCESS)
    {
        printf("Error: Failed to create compute kernel!\n");
        exit(1);
    }
    prm->count = prm->winx * prm->winy;
    prm->output = clCreateBuffer(prm->context, CL_MEM_WRITE_ONLY, prm->count * 4, NULL, NULL);
    if (!prm->output)
    {
        printf("Error: Failed to allocate device memory!\n");
        exit(1);
    }
    return (0);
}