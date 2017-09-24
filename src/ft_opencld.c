#include "fractol.h"
#include "get_next_line.h"
#include <stdio.h>

void          ft_setarg(t_ws *prm)
{
    int       err;

    printf("%.20lf\nit = %d\n\n", prm->zoom, prm->it);
    err = 0;
    err = clSetKernelArg(prm->kernel, 0, sizeof(cl_mem), &prm->output);
    err |= clSetKernelArg(prm->kernel, 1, sizeof(int), &prm->winx);
    err |= clSetKernelArg(prm->kernel, 2, sizeof(int), &prm->winy);
    err |= clSetKernelArg(prm->kernel, 3, sizeof(double), &prm->dec_x);
    err |= clSetKernelArg(prm->kernel, 4, sizeof(double), &prm->dec_y);
    err |= clSetKernelArg(prm->kernel, 5, sizeof(double), &prm->zoom);
    err |= clSetKernelArg(prm->kernel, 6, sizeof(char), &prm->fract);
    err |= clSetKernelArg(prm->kernel, 7, sizeof(int), &prm->it);
    err |= clSetKernelArg(prm->kernel, 8, sizeof(int), &prm->mousex);
    err |= clSetKernelArg(prm->kernel, 9, sizeof(int), &prm->mousey);
    err |= clSetKernelArg(prm->kernel, 10, sizeof(char), &prm->palette);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to set kernel arguments! %d\n", err);
        exit(1);
    }
}

int         ft_calc_fractal(t_ws *prm)
{
    int     err;

    ft_setarg(prm);
    printf("%i\n", CL_KERNEL_WORK_GROUP_SIZE);
    err = clGetKernelWorkGroupInfo(prm->kernel, prm->device_id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(prm->local), &prm->local, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to retrieve kernel work group info! %d\n", err);
        exit(1);
    }
    printf("%zu\n", prm->local);
    prm->global = (size_t)prm->count;
    err = clEnqueueNDRangeKernel(prm->commands, prm->kernel, 1, NULL, &prm->global, &prm->local, 0, NULL, NULL);
    if (err)
    {
        printf("Error: Failed to execute kernel!\n");
        return EXIT_FAILURE;
    }
    clFinish(prm->commands);
    err = clEnqueueReadBuffer(prm->commands, prm->output, CL_TRUE, 0, sizeof(char) * (prm->count * 4), prm->img_ad, 0, NULL, NULL );
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to read output array! %d\n", err);
        exit(1);
    }
    return (0);
}

void        ft_close_opencl(t_ws *prm)
{
    clReleaseMemObject(prm->output);
    clReleaseProgram(prm->program);
    clReleaseKernel(prm->kernel);
    clReleaseCommandQueue(prm->commands);
    clReleaseContext(prm->context);
}
