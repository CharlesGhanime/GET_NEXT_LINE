/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_retry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:15:01 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/19 20:16:19 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"



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
>>>>>>> 7eab96f01fa61a771e27fcdf55d2df768f7a17e7
}
*/

/*
 ** MAIN TEST
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int        main(int argc, char **argv)
{
	int        fd;
	char    *line;
	int        ret;
	int        i;

	fd = 0;
	if (argc > 1)
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (-1);
	ret = 1;
	i = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("line = %s\n", line);
		//printf("return = %d\n", ret);
		ft_strdel(&line);
	}
	//printf("final return = %d\n", ret);
	close(fd);
	return (0);
}
