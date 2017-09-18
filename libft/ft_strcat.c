/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:16:25 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/24 19:16:31 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	size_t	i1;
	size_t	i2;

	i1 = ft_strlen(dest);
	i2 = i1;
	while (src[i1 - i2])
	{
		dest[i1] = src[i1 - i2];
		i1++;
	}
	dest[i1] = src[i1 - i2];
	return (dest);
}
