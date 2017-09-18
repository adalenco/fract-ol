/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:05:01 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 11:05:02 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		if (s1[i] == '\0' && s2[i] != '\0')
			return (0);
		if (s2[i] == '\0' && s1[i] != '\0')
			return (0);
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}
