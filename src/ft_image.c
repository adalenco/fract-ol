/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 23:38:02 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/15 16:04:58 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		ft_refresh_image(t_ws *prm)
{
	mlx_destroy_image(prm->mlx, prm->img_ptr);
	prm->img_ptr = mlx_new_image(prm->mlx, prm->winx, prm->winy);
	prm->img_ad = mlx_get_data_addr(prm->img_ptr, &prm->bpp, \
			&prm->s_l, &prm->endian);
	clReleaseMemObject(prm->output);
	prm->output = clCreateBuffer(prm->context, CL_MEM_WRITE_ONLY, prm->count * 4, NULL, NULL);
    if (!prm->output)
    {
        printf("Error: Failed to allocate device memory!\n");
        exit(1);
    }
}
