/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:41:11 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/29 20:21:01 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	int read_return;
	char buffer[BUFFER_SIZE + 1];
	char *tmp;
	char *rest;
	//t_list *list;
	//list = NULL;
	//list =  malloc (sizeof(t_list));
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("open() failed");
			return (1);
		}
		tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
		while ((read_return = read(fd, buffer, BUFFER_SIZE)) && ft_strnchr(buffer, '\n') > 0)
		{
			if (rest == NULL)	
				rest = ft_strdup(buffer);
			else
			{
				tmp = malloc(sizeof(char ) * ft_strlen(rest) + BUFFER_SIZE + 1);
				tmp = ft_strcat(rest, buffer);
				rest = tmp;
			}
		}
		ft_putstr(rest);
		buffer[read_return] = '\0';
		if (close(fd) == -1)
		{
			ft_putstr("close() failed");
			return (1);
		}
	}
	else
		ft_putstr("Too few arguments");
	return (0);
}

