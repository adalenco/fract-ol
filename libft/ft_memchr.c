/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 03:04:13 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/13 03:04:18 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*strcpy;
	unsigned char	ccpy;

	ccpy = (unsigned char)c;
	strcpy = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (strcpy[i] == ccpy)
			return (strcpy + i);
		i++;
	}
	return (NULL);
}
