/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:25:28 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/20 18:57:44 by adalenco         ###   ########.fr       */
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
	prm->win = mlx_new_window(prm->mlx, prm->winx, prm->winy, "This is Fract'ol");
	prm->img_ptr = mlx_new_image(prm->mlx, prm->winx, prm->winy);
	prm->img_ad = mlx_get_data_addr(prm->img_ptr, &prm->bpp, &prm->s_l, &prm->endian);
	prm->mousex = 0;
	prm->mousey = 0;
}

void			ft_pixel_to_img(t_ws *prm, int x, int y, int color)
{
	int			pixel_pos;

	pixel_pos = 4 * x + y * prm->s_l;
	prm->img_ad[pixel_pos] = (color & 0x000000FF);
	prm->img_ad[pixel_pos + 1] = (color & 0x0000FF00) >> 8;
	prm->img_ad[pixel_pos + 2] = (color & 0x00FF0000) >> 16;
	prm->img_ad[pixel_pos + 3] = prm->endian;
}

void ft_parse_fract(t_ws *prm, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		prm->fract = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		prm->fract = 1;
	else
	{
		printf("usage : ./fractol [mandelbrot] or [julia]");
		exit(1);
	}
}

int				main(int ac, char **av)
{

	t_ws		prm;

	if (ac == 1)
		prm.fract = 0;
	else
		ft_parse_fract(&prm, av);
	ft_mlx_set(&prm, 1920, 1080);
	prm.zoom = 1;
	prm.it = 100;
	prm.mouseact = 0;
	//ft_mandel(&prm);
	ft_opencl_init(&prm);
	ft_calc_fractal(&prm);
	mlx_put_image_to_window(prm.mlx, prm.win, prm.img_ptr, 0, 0);
	mlx_hook(prm.win, KeyPress, KeyPressMask, ft_key_funct, &prm);
	mlx_hook(prm.win, MotionNotify, PointerMotionMask, ft_mouse_hook, &prm);
	mlx_hook(prm.win, ButtonPress, ButtonPressMask, ft_mouse_clic_hook, &prm);
	mlx_loop(prm.mlx);
	return (0);
}
