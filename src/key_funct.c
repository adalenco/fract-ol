/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:12:51 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/27 17:09:07 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_key_funct(int key, t_ws *prm)
{
	ft_bzero(prm->img_ad, prm->count * 4);
	if (key >= 83 && key <= 126)
		t_keyfunct(key, prm);
	else if (key == 0 || key == 1 || key == 2 ||
			key == 6 || key == 8 || key == 13)
		zoom_it_keyfunct(key, prm);
	else if (key == 35 || key == 12 || key == 53)
		reset_quit_keyfunct(key, prm);
	else if (key == 49 || key == 46 || key == 11)
		options_key(key, prm);
	else if (key == 17 || key == 15)
		swap_keyfunct(key, prm);
	else
		mult_keyfunct(key, prm);
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
