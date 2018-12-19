/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_retry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:15:01 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/19 01:17:51 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include "libft/libft.h"



int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int		ret;
	t_list	*lst;

	while ((ret = read(fd, buff, BUFF_SIZE) > 0) && 
	!(ft_strchr(buff, '\n')) && !(ft_strchr(buff, '\0')))
		{
			if (lst->content)
			{
				
			}
			buff[ret] = '\0';
			ft_memccpy(*line, buff, '\n', ret);
			if (BUFF_SIZE - ret != 0)
				{
					ft_strsub(lst->content, ft_strlen(*line) + 1,
					ft_strlen(lst->content) - ft_strlen(*line));
				}
		}
	return (**line);
}

/*
void	ft_multi_fd(int fd, t_list *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (lst->content_size = fd)
				return (fd)
			lst = ft_lstnew(NULL, 0);
			lst->content_size = fd;
		}
	}
	lst = ft_lstnew(NULL, 0);
	lst->content_size = fd;
}
*/

/*
 ** MAIN TEST
 */

#include <stdio.h>

int		main(int argc, char **argv)
{
	int fd;
	char *tab;
	
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			printf("open() failed");
			return (1);
		}

		while (get_next_line(fd, &tab) > 0)
		{
			printf("%s\n", tab);
			free(&tab);
		}

		if (close(fd) == -1)
		{
			printf("close() failed");
			return (1);
		}
	}
	else
		printf("Too few arguments");
	return (0);
}
