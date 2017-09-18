/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:30:21 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/27 22:17:23 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbsize(int n)
{
	int			div;
	int			size;

	if (n == -2147483648)
		return (11);
	size = 10;
	div = 1000000000;
	while (div >= 1)
	{
		if ((n / div) == 0)
		{
			div = div / 10;
			size--;
		}
		else
			break ;
	}
	if (size == 0)
		size = 1;
	if (n < 0)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*nbr;
	long int	ncpy;

	ncpy = (long int)n;
	if (!(nbr = (char *)malloc(nbsize(n) + 1)))
		return (NULL);
	i = nbsize(n) - 1;
	nbr[i + 1] = '\0';
	if (n == 0)
		nbr[i] = '0';
	if (n < 0)
	{
		ncpy = -ncpy;
		nbr[0] = '-';
	}
	while (ncpy > 0)
	{
		nbr[i] = (ncpy % 10) + '0';
		ncpy = ncpy / 10;
		i--;
	}
	return (nbr);
}
