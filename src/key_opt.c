/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 12:58:37 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/26 13:01:45 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		t_keyfunct(int key, t_ws *prm)
{
	if (key == 83)
		prm->dec_x -= 50;
	if (key == 85)
		prm->dec_x += 50;
	if (key == 84)
		prm->dec_y += 50;
	if (key == 87)
		prm->dec_y -= 50;
	if (key == 123)
		prm->dec_x -= 10;
	if (key == 124)
		prm->dec_x += 10;
	if (key == 125)
		prm->dec_y += 10;
	if (key == 126)
		prm->dec_y -= 10;
}

void		zoom_it_keyfunct(int key, t_ws *prm)
{
	if (key == 2)
		prm->it += 10;
	if (key == 0)
		prm->it -= 10;
	if (key == 6)
		prm->it -= 100;
	if (key == 8)
		prm->it += 100;
	if (key == 13)
	{
		prm->zoom /= 1.05;
		prm->dec_x *= 1.05;
		prm->dec_y *= 1.05;
	}
	if (key == 1)
	{
		prm->zoom *= 1.05;
		prm->dec_x /= 1.05;
		prm->dec_y /= 1.05;
	}
}

void		reset_quit_keyfunct(int key, t_ws *prm)
{
	if (key == 53 || key == 12)
	{
		opencl_close(prm);
		(void)prm;
		exit(0);
	}
	if (key == 35)
	{
		prm->it = 100;
		prm->mousey = prm->winy / 2;
		prm->mousex = prm->winx / 2;
		if (prm->fract == 6 || (prm->fract == 9 && prm->mult == 2))
		{
			prm->zoom = 1.25;
			prm->dec_x = 0;
			prm->dec_y = -180;
		}
		else
		{
			prm->zoom = 1;
			prm->dec_x = 0;
			prm->dec_y = 0;
		}
	}
}
