/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 20:25:28 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/15 17:09:09 by adalenco         ###   ########.fr       */
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

void			ft_mandel(t_ws *prm)
{

	double		img_x;
	double		img_y;
	double		x;
	double		y;
	double		i;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;

	prm->x1 = -2.1;
	prm->x2 = 0.6;
	prm->y1 = -1.2;
	prm->y2 = 1.2;
	img_x = (prm->x2 - prm->x1) * prm->zoom;
	img_y = (prm->y2 - prm->y1) * prm->zoom;
	x = 0;
	y = 0;
	while (x < img_x)
	{
		y = 0;
		while (y < img_y)
		{
			c_r = x / prm->zoom + prm->x1;
			c_i = y / prm->zoom + prm->y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < prm->it)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == prm->it && x + 950 - (prm->zoom) < prm->winx && x + 950 - (prm->zoom) > 0 && y + 540 - (prm->zoom) < prm->winy && y + 540 - (prm->zoom) > 0)
				ft_pixel_to_img(prm, x + 950 - (prm->zoom), y + 540 - (prm->zoom), 0x00000000);
			else if (x + 950 - (prm->zoom) < prm->winx && x + 950 - (prm->zoom) > 0 && y + 540 - (prm->zoom) < prm->winy && y + 540 - (prm->zoom) > 0)
				ft_pixel_to_img(prm, x + 950 - (prm->zoom), y + 540 - (prm->zoom), 0x00000000 + (16 * i));
			y++;
		}
		x++;
	}
}

int				main(void)
{

	t_ws		prm;

	ft_mlx_set(&prm, 1900, 1080);
	printf("%lf\n", DBL_MAX);
	prm.zoom = 200;
	prm.it = 100;
	//ft_mandel(&prm);
	ft_opencl_init(&prm);
	ft_calc_fractal(&prm);
	mlx_put_image_to_window(prm.mlx, prm.win, prm.img_ptr, 0, 0);
	mlx_hook(prm.win, KeyPress, KeyPressMask, ft_key_funct, &prm);
	mlx_loop(prm.mlx);
	return (0);
}
