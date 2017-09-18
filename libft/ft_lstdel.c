/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:54:55 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/29 16:54:56 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cpy;
	t_list	*nxtlst;

	if (del == NULL)
		return ;
	cpy = *alst;
	while (cpy)
	{
		nxtlst = cpy->next;
		del(cpy->content, cpy->content_size);
		free(cpy);
		cpy = nxtlst;
	}
	*alst = NULL;
}
