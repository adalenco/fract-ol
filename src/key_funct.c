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

void		t_keyfunct(int keycode, t_ws *prm)
{
	if (keycode == 83)
		prm->dec_x -= 50;
	if (keycode == 85)
		prm->dec_x += 50;
	if (keycode == 84)
		prm->dec_y += 50;
	if (keycode == 87)
		prm->dec_y -= 50;
	if (keycode == 123)
		prm->dec_x -= 10;
	if (keycode == 124)
		prm->dec_x += 10;
	if (keycode == 125)
		prm->dec_y += 10;
	if (keycode == 126)
		prm->dec_y -= 10;
}

int			ft_key_funct(int keycode, t_ws *prm)
{
	//printf("keycode = %d\n", keycode);
	ft_bzero(prm->img_ad, prm->count * 4);
	if (keycode >= 83 && keycode <= 126)
		t_keyfunct(keycode, prm);
	if (keycode == 53 || keycode == 12)
	{
		opencl_close(prm);
		(void)prm;
		exit(0);
	}
	if (keycode == 2)
		prm->it += 10;
	if (keycode == 0)
		prm->it -= 10;
	if (keycode == 6)
		prm->it -= 100;
	if (keycode == 8)
		prm->it += 100;
	if (keycode == 17)
	{
		prm->fract = 0;
		keycode = 35;
	}
	if (keycode == 16)
	{
		prm->fract = 1;
		keycode = 35;
	}
	if (keycode == 32)
	{
		prm->fract = 2;
		keycode = 35;
	}
	if (keycode == 5)
	{
		prm->fract = 3;
		keycode = 35;
	}
	if (keycode == 4)
	{
		prm->fract = 4;
		keycode = 35;
	}
	if (keycode == 38)
	{
		prm->fract = 5;
		keycode = 35;
	}
	if (keycode == 35)
	{
		prm->mousey = prm->winy / 2;
		prm->mousex = prm->winx / 2;
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
	
	if (keycode == 49)
	{
		if (prm->mouseact == 0)
			prm->mouseact = 1;
		else
			prm->mouseact = 0;
	}
	if (keycode == 46)
	{
		if (prm->palette == 2)
			prm->palette = 1;
		else
			prm->palette = 2;
	}

	draw_fractal(prm);
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
		draw_fractal(prm);
		mlx_put_image_to_window(prm->mlx, prm->win, prm->img_ptr, 0, 0);
	}
	return (0);
}

int			ft_mouse_clic_hook(int button, int x, int y, t_ws *prm)
{
	double ozoom;

	ft_bzero(prm->img_ad, prm->count * 4);
	if (button == 4)
	{
		ozoom = prm->zoom;
		prm->zoom /= 1.15;
		prm->dec_x = (x + prm->dec_x - 960) * ozoom / prm->zoom + 960 - x;
		prm->dec_y = (y + prm->dec_y - 540) * ozoom / prm->zoom + 540 - y;
	}
	if (button == 5)
	{
		ozoom = prm->zoom;
		prm->zoom *= 1.15;
		prm->dec_x = (x + prm->dec_x - 960) * ozoom / prm->zoom + 960 - x;
		prm->dec_y = (y + prm->dec_y - 540) * ozoom / prm->zoom + 540 - y;
	}
	draw_fractal(prm);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->img_ptr, 0, 0);
	return (0);
}
