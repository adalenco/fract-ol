/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 08:15:46 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/26 08:15:47 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *str1, const char *str2, int n)
{
	int	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
