/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:41:46 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/29 16:41:47 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(sizeof(content))))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		if (!(list->content_size = (size_t)malloc(sizeof(size_t))))
			return (NULL);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
