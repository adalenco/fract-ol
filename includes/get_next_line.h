/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 23:12:47 by adalenco          #+#    #+#             */
/*   Updated: 2017/09/14 19:28:46 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 42

typedef struct		s_gnllist
{
	int				fd;
	char			*stock;
	void			*next;
}					t_gnllist;

int					get_next_line(const int fd, char **line);

#endif
