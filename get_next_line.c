/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:15:01 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/16 22:00:10 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int		ft_check(const int fd)
{
	if (fd == -1)
	{
		ft_putstr("open failed");
		return (-1);
	}
	return (fd);
}
t_list	*ft_filling_list(const int fd, t_list *lst)
{
	int		read_return;
	char	buff[BUFF_SIZE + 1];
	char *tmp;
	int i;

	i = BUFF_SIZE;
	while (read_return = read(fd, buff, BUFF_SIZE))
	{
		if (!lst)
		{
			if (tmp)
			{
				lst = ft_lstnew(NULL, 0);
				lst->content = ft_memccpy(lst->content, tmp, '\n', BUFF_SIZE);
				lst->content_size = fd;
			}
			else
			lst = ft_lstnew(NULL, 0);
			ft_memccpy(lst->content, buff, '\n', BUFF_SIZE);
			lst->content_size = fd;
			buff[i] = '\0';
			while (buff[i + 1] != '\0')
				ft_strcpy(tmp, buff);
		}
		while (lst)
		{
			if (lst->content_size == fd)
				break;
			lst = lst->next;
		}
	}
	return (lst);
}

int		main()
{
	
	return (0);
}
