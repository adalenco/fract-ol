/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 06:53:28 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 06:53:31 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(char *str1, char *str2)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;

	if (str2[0] == '\0')
		return (str1);
	i1 = 0;
	while (str1[i1])
	{
		i2 = i1;
		i3 = 0;
		while (str1[i2] == str2[i3])
		{
			if (str2[i3 + 1] == 0)
				return (str1 + i1);
			i2++;
			i3++;
		}
		i1++;
	}
	return (NULL);
}
