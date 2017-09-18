/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:23:00 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 11:23:01 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countspc(const char *str)
{
	int			i;
	size_t		spc;

	i = 0;
	spc = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		spc++;
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		spc++;
		i--;
	}
	if (i == -1)
		spc = ft_strlen(str);
	return (spc);
}

char			*ft_strtrim(char const *s)
{
	int			i1;
	int			i2;
	int			end;
	char		*cpy;

	if ((s == NULL) || !(cpy = (char *)malloc(sizeof(char) *
		(ft_strlen(s) + 1 - ft_countspc(s)))))
		return (NULL);
	i1 = ft_strlen(s) - 1;
	i2 = 0;
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1--;
	end = i1;
	i1 = 0;
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1++;
	while (i1 <= end)
	{
		cpy[i2] = s[i1];
		i1++;
		i2++;
	}
	cpy[i2] = '\0';
	return (cpy);
}
