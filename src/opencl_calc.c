/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:40:05 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/27 17:08:54 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_setarg(t_ws *prm)
{
	int		err;

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
	err |= clSetKernelArg(prm->kernel, 11, sizeof(int), &prm->newton);
	err |= clSetKernelArg(prm->kernel, 12, sizeof(char), &prm->ncolor);
	err |= clSetKernelArg(prm->kernel, 13, sizeof(int), &prm->mult);
	if (err != CL_SUCCESS)
	{
		ft_putstr("Error: Failed to set kernel arguments!");
		ft_putnbr(err);
		ft_putchar('\n');
		exit(1);
	}
}

int			get_imgptr(t_ws *prm)
{
	int		err;

	clFinish(prm->commands);
	err = clEnqueueReadBuffer(prm->commands, prm->output, CL_TRUE, 0, \
			sizeof(char) * (prm->count * 4), prm->img_ad, 0, NULL, NULL);
	if (err != CL_SUCCESS)
	{
		ft_putstr("Error: Failed to read output array!");
		ft_putnbr(err);
		ft_putchar('\n');
		exit(1);
	}
	return (0);
}

int			draw_fractal(t_ws *prm)
{
	int		err;

	ft_setarg(prm);
	err = clGetKernelWorkGroupInfo(prm->kernel, prm->device_id, \
			CL_KERNEL_WORK_GROUP_SIZE, sizeof(prm->local), &prm->local, NULL);
	if (err != CL_SUCCESS)
	{
		ft_putstr("Error: Failed to retrieve kernel work group info!");
		ft_putnbr(err);
		ft_putchar('\n');
		exit(1);
	}
	prm->global = (size_t)prm->count;
	err = clEnqueueNDRangeKernel(prm->commands, prm->kernel, 1, NULL, \
			&prm->global, &prm->local, 0, NULL, NULL);
	if (err)
	{
		ft_putstr("Error: Failed to execute kernel!\n");
		return (EXIT_FAILURE);
	}
	get_imgptr(prm);
	return (0);
}

void		opencl_close(t_ws *prm)
{
	clReleaseMemObject(prm->output);
	clReleaseProgram(prm->program);
	clReleaseKernel(prm->kernel);
	clReleaseCommandQueue(prm->commands);
	clReleaseContext(prm->context);
}
