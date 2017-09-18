/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:54:18 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 10:54:21 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_addlen(char const *s1, char const *s2)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (s1[i1])
		i1++;
	while (s2[i2])
		i2++;
	return (i1 + i2);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	int		len;
	char	*nstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i1 = 0;
	i2 = 0;
	len = ft_addlen(s1, s2) + 1;
	if (!(nstr = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (s1[i1])
	{
		nstr[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		nstr[i1] = s2[i2];
		i1++;
		i2++;
	}
	nstr[i1] = '\0';
	return (nstr);
}
