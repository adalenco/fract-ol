/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:05:18 by adalenco          #+#    #+#             */
/*   Updated: 2016/11/29 17:05:20 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*cpy;

	if (lst == NULL || f == NULL)
		return ;
	cpy = lst;
	while (cpy->next)
	{
		f(cpy);
		cpy = cpy->next;
	}
	f(cpy);
}
