/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:03:10 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 11:03:12 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nstr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(nstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
