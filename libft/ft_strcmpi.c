/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 07:33:37 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 07:33:40 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmpi(const char *str1, const char *str2, size_t i1, size_t i2)
{
	while (str1[i1] || str2[i2])
	{
		if (str1[i1] != str2[i2])
			return (str1[i1] - str2[i2]);
		i1++;
		i2++;
	}
	return (0);
}
