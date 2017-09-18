/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarrayendl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:38:15 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/28 22:38:16 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarrayendl(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		i++;
	}
}
