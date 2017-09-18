/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 02:21:08 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/13 02:21:10 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dstcpy;
	unsigned char	*srccpy;
	unsigned char	tmp;

	i = 0;
	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	if (srccpy < dstcpy)
	{
		while (len--)
			*(dstcpy + len) = *(srccpy + len);
	}
	else
		while (i < len)
		{
			tmp = srccpy[i];
			dstcpy[i] = tmp;
			i++;
		}
	return (dst);
}
