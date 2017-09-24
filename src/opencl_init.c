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

void        opencl_builderrors(t_ws *prm, int err)
{
    size_t len;

    if (err == 1)
        printf("Error: Failed to create a device group!\n");
    else if (err == 2)
        printf("Error: Failed to create a compute context!\n");
    else if (err == 3)
        printf("Error: Failed to create a command commands!\n");
    else if (err == 4)
        printf("Error: Failed to create compute program!\n");
    else if (err == 5)
    {
        char buffer[50000];
        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(prm->program, prm->device_id, \
                CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
    }
    else if (err == 6)
        printf("Error: Failed to create compute kernel!\n");
    else if (err = 7)
        printf("Error: Failed to allocate device memory!\n");
    if (err >= 5)
        exit(1);
    return EXIT_FAILURE;
}

int         opencl_build(t_ws *prm)
{
    int err;

    if ((err = clBuildProgram(prm->program, 0, NULL, NULL, NULL, \
                NULL)) != CL_SUCCESS)
        return (opencl_builderrors(5));
    if (!(prm->kernel = clCreateKernel(prm->program, "fractal", &err)) \
                || err!= CL_SUCCESS)
        return (opencl_builderrors(6));
    prm->count = prm->winx * prm->winy;
    if (!(prm->output = clCreateBuffer(prm->context, CL_MEM_WRITE_ONLY, \
                prm->count * 4, NULL, NULL)))
        return (opencl_builderrors(7));
    return (0)
}

int         opencl_init(t_ws *prm)
{
    int     gpu;
    int     err;

    gpu = 1;
    ft_loadkernel(prm);
    if ((err = clGetDeviceIDs(NULL, gpu ? CL_DEVICE_TYPE_GPU : \
                CL_DEVICE_TYPE_CPU, 1, &prm->device_id, NULL)) != CL_SUCCESS)
        return (opencl_builderrors(1));
    if (!(prm->context = clCreateContext(0, 1, &prm->device_id, \
                NULL, NULL, &err)))
        return (opencl_builderrors(2));
    if (!(prm->commands = clCreateCommandQueue(prm->context, \
                prm->device_id, 0, &err)))
        return (opencl_builderrors(3));
    if (!(prm->program = clCreateProgramWithSource(prm->context, 1, \
                (const char **) & prm->KernelSource, NULL, &err)))
       return (opencl_builderrors(4));
    opencl_build(prm);
    return (0);
}
