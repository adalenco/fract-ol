/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:39:42 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/24 19:39:44 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	i2;

	i = ft_strlen(dest);
	i2 = i;
	while ((i - i2 < n) && src[i - i2])
	{
		dest[i] = src[i - i2];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
