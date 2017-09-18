/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 00:34:38 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/13 00:34:42 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	cpy = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		cpy[i] = 0;
		i++;
	}
	return (str);
}
