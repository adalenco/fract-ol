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
		prm->mousey = prm->winy / 2;
		prm->mousex = prm->winx / 2;
		if (prm->fract != 6)
		{
			prm->zoom = 1;
			prm->dec_x = 0;
			prm->dec_y = 0;
		}
		else
		{
			prm->fract = 6;
			prm->zoom = 1.25;
			prm->dec_y = -180;
		}
	}
}

void		swap_keyfunct(int key, t_ws *prm)
{
	if (key == 17)
	{
		if (prm->fract == 13)
			prm->fract = 0;
		else
			prm->fract++;
	}
	else if (key == 45)
	{
		if (prm->newton == 5)
			prm->newton = 0;
		else
			prm->newton++;
	}
	else if (key == 78)
	{
		if (prm->mult != 1)
			prm->mult--;
	}
	else if (key == 69)
		prm->mult++;
	else if (key == 67)
		prm->mult = 1;
	reset_quit_keyfunct(35, prm);
}

void		options_key(int key, t_ws *prm)
{
	if (key == 49)
	{
		if (prm->mouseact == 0)
			prm->mouseact = 1;
		else
			prm->mouseact = 0;
	}
	if (key == 46)
	{
		if (prm->palette == 2)
			prm->palette = 1;
		else
			prm->palette = 2;
	}
	if (key == 11)
	{
		if (prm->ncolor == 0)
			prm->ncolor++;
		else
			prm->ncolor--;
	}
}
