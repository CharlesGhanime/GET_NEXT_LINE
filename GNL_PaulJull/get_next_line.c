/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:48:57 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/19 22:35:41 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

t_list		*ft_multi_fd(int fd, t_list *lst)
{
	t_list *node;

	if (lst)
	{
		node = lst;
		while (node)
		{
			if (node->next->content_size == fd)
			{
				node->next->next = lst;
				node->next = node->next->next;
				return (node->next);
			}
			node = node->next;
		}
		node = ft_lstnew(NULL, fd);
		node->next = lst;
		return (node);
	}
	lst = ft_lstnew(NULL, fd);
	return (lst);
}

int		ft_fill_line(t_list *lst, char **line)
{
	char    *tmp;
	int     index;
	index = 0;
	while (((char *)lst->content)[index] != '\n' && ((char *)lst->content)[index] != '\0')
		index += 1;
	if (index == 0)
		return (0);
	*line = ft_strnew(index);
	ft_strncpy(*line, lst->content, index);
	tmp = lst->content;
	lst->content = ft_strsub(lst->content, ft_strlen(*line) + 1, ft_strlen(lst->content) - ft_strlen(*line));
	free(tmp);
	return (1);
}

int		ft_read(t_list *lst, char **line, int fd)
{
	char            buff[BUFF_SIZE + 1];
	int             ret;

	ft_bzero(buff, BUFF_SIZE + 1);
	while (!ft_strchr(buff, '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = 0;
		if (ret == 0)
			break ;
		lst->content = ft_strjoinf((char *)lst->content, buff, 1);
	}
	if ((ft_fill_line(lst, line) == 0) && ret < BUFF_SIZE)
		return (0);
	return (1);
}

int     get_next_line(const int fd, char **line)
{
	static t_list   *lst;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	lst = ft_multi_fd(fd, lst);
	if (lst)
	{
			if (ft_strchr(lst->content, '\n'))
				return (ft_fill_line(lst, line));
		return (ft_read(lst, line, fd));
	}
	/*if (!lst)
	{
		if (!(lst = ft_lstnew(NULL, fd)))
			return (-1);
		lst->content_size = fd;
		return (ft_read(lst, line, fd));
	}*/
		return (1);
}
