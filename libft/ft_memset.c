/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 00:36:18 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/13 00:36:20 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (n == 0)
		return (str);
	tmp = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
