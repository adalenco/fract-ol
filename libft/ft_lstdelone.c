/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:49:07 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/29 16:49:07 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cpy;

	if (del == NULL)
		return ;
	if (alst && *alst)
	{
		cpy = *alst;
		del(cpy->content, cpy->content_size);
		free(*alst);
		*alst = NULL;
	}
}
