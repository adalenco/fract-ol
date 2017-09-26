/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:25:28 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/26 13:58:02 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <float.h>

void			ft_mlx_set(t_ws *prm, int x, int y)
{
	prm->winx = x;
	prm->winy = y;
	prm->dec_y = 0;
	prm->dec_x = 0;
	prm->mlx = mlx_init();
	prm->win = mlx_new_window(prm->mlx, prm->winx, prm->winy, \
			"This is Fract'ol");
	prm->img_ptr = mlx_new_image(prm->mlx, prm->winx, prm->winy);
	prm->img_ad = mlx_get_data_addr(prm->img_ptr, &prm->bpp, \
			&prm->s_l, &prm->endian);
	prm->mousex = x / 2;
	prm->mousey = y / 2;
	prm->palette = 1;
	prm->zoom = 1;
	prm->it = 100;
	prm->mouseact = 0;
	prm->newton = 0;
	prm->ncolor = 0;
}

void			ft_parse_fract(t_ws *prm, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		prm->fract = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		prm->fract = 1;
	else if (ft_strcmp(av[1], "bship") == 0)
		prm->fract = 2;
	else if (ft_strcmp(av[1], "celtic") == 0)
		prm->fract = 3;
	else if (ft_strcmp(av[1], "tricorn") == 0)
		prm->fract = 4;
	else if (ft_strcmp(av[1], "spaceship") == 0)
		prm->fract = 5;
	else if (ft_strcmp(av[1], "mandeldrop") == 0)
	{
		prm->fract = 6;
		prm->zoom = 1.25;
		prm->dec_y = -180;
	}
	else if (ft_strcmp(av[1], "newton") == 0)
		prm->fract = 7;
	else if (ft_strcmp(av[1], "multibrot") == 0)
		prm->fract = 8;
	else
	{
		printf("usage : ./fractol \"fractal name\"\n");
		exit(1);
	}
}

int				main(int ac, char **av)
{
	t_ws		prm;

	ft_mlx_set(&prm, 1920, 1080);
	if (ac == 1 || ac > 2)
	{
		printf("usage : ./fractol \"fractal name\"\n");
		return (-1);
	}
	else
		ft_parse_fract(&prm, av);
	opencl_init(&prm);
	draw_fractal(&prm);
	mlx_put_image_to_window(prm.mlx, prm.win, prm.img_ptr, 0, 0);
	mlx_hook(prm.win, KeyPress, KeyPressMask, ft_key_funct, &prm);
	mlx_hook(prm.win, MotionNotify, PointerMotionMask, ft_mouse_hook, &prm);
	mlx_hook(prm.win, ButtonPress, ButtonPressMask, ft_mouse_clic_hook, &prm);
	mlx_loop(prm.mlx);
	return (0);
}
