/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:59:54 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 10:59:55 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char *s, char (*f)(char))
{
	int		i;
	char	*nstr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(nstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		nstr[i] = f(s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
