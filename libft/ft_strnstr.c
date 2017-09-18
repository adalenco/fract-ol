/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 08:02:19 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 08:02:20 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(char *str1, char *str2, size_t n)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;

	i1 = 0;
	i3 = 0;
	if (str2[0] == '\0')
		return (str1);
	while (i1 < n && str1[i1])
	{
		i2 = i1;
		while (str1[i2] == str2[i3])
		{
			if (i2 == n)
				return (NULL);
			if (str2[i3 + 1] == 0)
				return (str1 + i1);
			i2++;
			i3++;
		}
		i3 = 0;
		i1++;
	}
	return (NULL);
}
