/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ultime.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:01:04 by cghanime          #+#    #+#             */
/*   Updated: 2019/01/12 14:53:08 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>

t_list		*ft_multi_fd(int fd, t_list *lst)
{
	t_list *head;
	t_list *node;

	head = lst;
	while (lst)
	{
		if (lst->content_size == (size_t)fd)
			return (lst);
		lst = lst->next;
	}
	ft_lst_push_back(&head, NULL, 0);
	node = ft_lst_last(head);
	node->content_size = fd;
	return (node);
}

void		ft_filling_line(t_list *lst, char **line)
{
	char *tmp;
	int i;

	i = 0;
	while (((char *)lst->content)[i] != '\0' && ((char *)lst->content)[i] != '\n')
		i++;
	if ((char *)lst->content != '\0')
	{
		if (!(*line = ft_strnew(i)))
			return ;
		ft_strncpy(*line, lst->content, i);
		tmp = lst->content;
		if (((char *)lst->content)[0] == '\0')
			return ;
		if (ft_strlen(*line) == ft_strlen(lst->content))
			lst->content = ft_strsub(lst->content, ft_strlen(lst->content), 1);
		else
		{
			lst->content = ft_strsub(lst->content, ft_strlen(*line) + 1, 
			ft_strlen(lst->content) - ft_strlen(*line) - 1);
		}
		if (!(lst->content))
			return ;
		free(tmp);
	}
}

int		ft_reading_files(t_list *lst, char **line, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	ft_bzero(buff, BUFF_SIZE + 1);
	while (!ft_strchr(buff, '\n'))
	{
		if ((ret = read(fd, buff, BUFF_SIZE) < 0))
			return (-1);
		buff[ret] = '\0';
		if (!(lst->content = ft_strjoinf((char *)lst->content, buff, 1)))
			return (-1);
		if (ret == 0)
			break ;
	}
	if (((char *)lst->content)[0] == '\0' && ret == 0)
		return (0);
	ft_filling_line(lst, line);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list *lst;
	t_list	*buff_lst;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!lst)
	{
		if (!(lst = ft_lstnew(NULL, fd)))
				return (-1);
		lst->content_size = fd;
	}
	if (!(buff_lst = ft_multi_fd(fd, lst)))
		return (-1);
	if (ft_strchr(buff_lst->content, '\n'))
	{
		ft_filling_line(buff_lst, line);
		return (1);
	}
	return (ft_reading_files(buff_lst, line, fd));
}
