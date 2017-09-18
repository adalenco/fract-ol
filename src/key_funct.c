/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:12:51 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/15 16:16:58 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			ft_key_funct(int keycode, t_ws *prm)
{
	ft_refresh_image(prm);
	if (keycode == 53 || keycode == 12)
	{
		ft_close_opencl(prm);
		(void)prm;
		exit(0);
	}
	if (keycode == 2)
		prm->it += 10;
	if (keycode == 0)
		prm->it -= 10;
	if (keycode == 35)
	{
		prm->zoom = 200;
		prm->dec_x = 0;
		prm->dec_y = 0;
	}
	if (keycode == 13)
	{
		prm->zoom /= 1.1;
		prm->dec_x /= 1.1;
		prm->dec_y /= 1.1;
	}
	if (keycode == 1)
	{
		prm->zoom *= 1.1;
		prm->dec_x *= 1.1;
		prm->dec_y *= 1.1;
	}
	if (keycode == 83)
		prm->dec_x -= 50 + (prm->zoom / 100);
	if (keycode == 85)
		prm->dec_x += 50 + (prm->zoom / 100);
	if (keycode == 84)
		prm->dec_y -= 50 + (prm->zoom / 100);
	if (keycode == 87)
		prm->dec_y += 50 + (prm->zoom / 100);
	if (keycode == 123) // gauche
		prm->dec_x -= 10;
	if (keycode == 124) // droite
		prm->dec_x += 10;
	if (keycode == 125) // haut
		prm->dec_y += 10;
	if (keycode == 126) // bas
		prm->dec_y -= 10;

	ft_calc_fractal(prm);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->img_ptr, 0, 0);
	return (0);
}
