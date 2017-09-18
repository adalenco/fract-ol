/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 00:45:11 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/13 00:45:13 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpysrc;
	unsigned char	*cpydst;

	cpysrc = (unsigned char *)src;
	cpydst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		cpydst[i] = cpysrc[i];
		i++;
	}
	return (dst);
}
