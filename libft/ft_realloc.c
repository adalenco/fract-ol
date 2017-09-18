/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:28:40 by adalenco          #+#    #+#             */
/*   Updated: 2017/01/26 18:28:43 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;
	size_t	i;

	if (size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}
	if (!(newptr = ft_memalloc(sizeof(char) * size)))
		return (NULL);
	if (ptr == NULL)
		return (newptr);
	i = ft_strlen((char *)ptr);
	ft_memcpy(newptr, ptr, (i + 1));
	ft_memdel(&ptr);
	return (newptr);
}
