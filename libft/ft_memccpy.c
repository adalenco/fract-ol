/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 01:37:56 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/13 01:37:58 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpydst;
	unsigned char	*cpysrc;

	i = 0;
	cpysrc = (unsigned char *)src;
	cpydst = (unsigned char *)dst;
	while (i < n)
	{
		cpydst[i] = cpysrc[i];
		if (cpysrc[i] == (unsigned char)c)
			return (cpydst + (i + 1));
		i++;
	}
	return (NULL);
}
