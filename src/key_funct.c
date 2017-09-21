/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:12:51 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/20 19:05:28 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			ft_key_funct(int keycode, t_ws *prm)
{
	//ft_refresh_image(prm);
	//printf("%d\n", keycode);
	ft_bzero(prm->img_ad, prm->count * 4);
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
		prm->zoom = 1;
		prm->dec_x = 0;
		prm->dec_y = 0;
	}
	if (keycode == 13)
	{
		prm->zoom /= 1.05;
		prm->dec_x *= 1.05;
		prm->dec_y *= 1.05;
	}
	if (keycode == 1)
	{
		prm->zoom *= 1.05;
		prm->dec_x /= 1.05;
		prm->dec_y /= 1.05;
	}
	if (keycode == 83)
		prm->dec_x -= 50;
	if (keycode == 85)
		prm->dec_x += 50;
	if (keycode == 84)
		prm->dec_y += 50;
	if (keycode == 87)
		prm->dec_y -= 50;
	if (keycode == 123) // gauche
		prm->dec_x -= 10;
	if (keycode == 124) // droite
		prm->dec_x += 10;
	if (keycode == 125) // haut
		prm->dec_y += 10;
	if (keycode == 126) // bas
		prm->dec_y -= 10;
	if (keycode == 49) // space
	{
		if (prm->mouseact == 0)
			prm->mouseact = 1;
		else
			prm->mouseact = 0;
	}
	ft_calc_fractal(prm);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->img_ptr, 0, 0);
	return (0);
}

int			ft_mouse_hook(int x, int y, t_ws *prm)
{
	if (prm->mouseact == 1)
	{
		ft_bzero(prm->img_ad, prm->count * 4);
		prm->mousex = x;
		prm->mousey = y;
		ft_calc_fractal(prm);
		mlx_put_image_to_window(prm->mlx, prm->win, prm->img_ptr, 0, 0);
	}
	return (0);
}

int			ft_mouse_clic_hook(int button, int x, int y, t_ws *prm)
{
	double ozoom;

	ft_bzero(prm->img_ad, prm->count * 4);
	if (button == 4) // scroll up
	{
		ozoom = prm->zoom;
		prm->zoom /= 1.15;
		prm->dec_x = (x + prm->dec_x - 960) * ozoom / prm->zoom + 960 - x;
		prm->dec_y = (y + prm->dec_y - 540) * ozoom / prm->zoom + 540 - y;
	}
	if (button == 5) // scroll down
	{
		ozoom = prm->zoom;
		prm->zoom *= 1.15;
		prm->dec_x = (x + prm->dec_x - 960) * ozoom / prm->zoom + 960 - x;
		prm->dec_y = (y + prm->dec_y - 540) * ozoom / prm->zoom + 540 - y;
	}
	//prm->mousex = x;
	//prm->mousey = y;
	ft_calc_fractal(prm);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->img_ptr, 0, 0);
	return (0);
}
