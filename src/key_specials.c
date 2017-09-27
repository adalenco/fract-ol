/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_specials.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:31:35 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/27 16:31:36 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mult_keyfunct(int key, t_ws *prm)
{
	if (key == 45 && prm->fract == 7)
	{
		if (prm->newton == 5)
			prm->newton = 0;
		else
			prm->newton++;
        reset_quit_keyfunct(35, prm);
	}
	else if (key == 78 && prm->fract > 7)
	{
		if (prm->mult != 1)
			prm->mult--;
	}
	else if (key == 69 && prm->fract > 7)
		prm->mult++;
	else if (key == 67 && prm->fract > 7)
		prm->mult = 1;
    if (prm->fract > 7)
	   reset_quit_keyfunct(35, prm);
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
	if (key == 15)
	{
		if (prm->fract == 0)
			prm->fract = 13;
		else
			prm->fract--;
	}
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
