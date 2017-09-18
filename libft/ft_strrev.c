/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:40:02 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/27 19:40:04 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i1;
	int		i2;
	char	*rev;

	if (!(rev = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i1 = 0;
	i2 = ft_strlen(str) - 1;
	while (i2 >= 0)
	{
		rev[i1] = str[i2];
		i1++;
		i2--;
	}
	rev[i1] = '\0';
	return (rev);
}
