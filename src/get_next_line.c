/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:15:38 by adalenco          #+#    #+#             */
/*   Updated: 2017/03/14 20:28:51 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnllist		*list_new(int fd)
{
	t_gnllist			*list;

	if (!(list = (t_gnllist *)malloc(sizeof(t_gnllist))) ||
			!(list->stock = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	list->fd = fd;
	list->next = NULL;
	return (list);
}

static int				feed_line_and_stock(char **line,
						t_gnllist *list, char *buf)
{
	int					i;
	char				*tmp;

	i = 0;
	while (buf[i] != '\n')
		i++;
	list->stock = ft_strcpy(list->stock, (char *)(buf + i + 1));
	buf[i] = '\0';
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	ft_memdel((void **)&tmp);
	return (1);
}

static int				read_on_buf(char **line, t_gnllist *list, int fd)
{
	char				*buf;
	int					ret;
	char				*tmp;

	if (!(buf = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) >= 0)
	{
		if (ret == 0)
		{
			ft_memdel((void **)&buf);
			if (ft_strlen(*line) != 0)
				return (1);
			ft_memdel((void **)line);
			return (0);
		}
		if (ft_strchr(buf, '\n') != NULL)
			return (feed_line_and_stock(line, list, buf));
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_memdel((void **)&tmp);
		ft_bzero(buf, ft_strlen(buf));
	}
	return (-1);
}

static int				what_in_stock(char **line, t_gnllist *list)
{
	char				*cpy;
	char				*tmp;
	size_t				i;

	i = 0;
	cpy = ft_strdup(list->stock);
	while (cpy[i] && cpy[i] != '\n')
		i++;
	if (i == ft_strlen(cpy))
	{
		tmp = *line;
		*line = ft_strjoin(*line, cpy);
		ft_bzero(list->stock, ft_strlen(list->stock));
		ft_memdel((void **)&cpy);
		ft_memdel((void **)&tmp);
		return (read_on_buf(line, list, list->fd));
	}
	*line = ft_strncpy(*line, list->stock, i);
	list->stock = ft_strcpy(list->stock, (list->stock + i + 1));
	ft_memdel((void **)&cpy);
	return (1);
}

int						get_next_line(const int fd, char **line)
{
	static t_gnllist	*list = NULL;
	t_gnllist			*tmp;

	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL ||
			(!(*line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1))))
		return (-1);
	if (list != NULL)
	{
		tmp = list;
		while (tmp->next)
		{
			if (tmp->fd == fd)
				return (what_in_stock(line, tmp));
			tmp = tmp->next;
		}
		if (tmp->fd == fd)
			return (what_in_stock(line, tmp));
		if (!(tmp->next = list_new(fd)))
			return (-1);
		return (read_on_buf(line, tmp->next, fd));
	}
	if (!(list = list_new(fd)))
		return (-1);
	return (read_on_buf(line, list, fd));
}
