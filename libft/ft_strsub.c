/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:08:18 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 11:08:18 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			i2;
	char			*nstr;

	i = start;
	i2 = 0;
	if (s == NULL)
		return (NULL);
	if (!(nstr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i2 < len)
	{
		nstr[i2] = s[i];
		i++;
		i2++;
	}
	nstr[i2] = '\0';
	return (nstr);
}
