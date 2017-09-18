/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:52:52 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/27 17:52:54 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_avoidc(const char *str, char c, int i)
{
	if (i != 0)
	{
		while (str[i] != c)
			i++;
	}
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			return (i);
	}
	return (i);
}

static char			*ft_cut(const char *str, char c, int i1)
{
	char			*word;
	int				i2;
	int				iword;

	i2 = i1;
	iword = 0;
	while (str[i2] && str[i2] != c)
		i2++;
	if (!(word = (char *)ft_memalloc(i2 - i1)))
		return (NULL);
	while (i1 < i2)
	{
		word[iword] = str[i1];
		iword++;
		i1++;
	}
	word[iword] = '\0';
	return (word);
}

static size_t		ft_countwords(const char *str, char c)
{
	int				i;
	size_t			n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			n++;
			while (str[i + 1] != c && str[i + 1])
				i++;
		}
		i++;
	}
	return (n);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t			i;
	int				word;
	char			**split;

	if (s == NULL)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char *) * ft_countwords(s, c) + 1)))
		return (NULL);
	i = 0;
	word = 0;
	while (i < ft_countwords(s, c))
	{
		word = ft_avoidc(s, c, word);
		split[i] = ft_cut(s, c, word);
		if (word == 0)
			word++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
