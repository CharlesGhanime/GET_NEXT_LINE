/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:41:11 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/04 21:28:33 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int read_return;
	char buffer[BUFFER_SIZE + 1];
	char *tmp;
	char *rest;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((read_return = read(fd, buffer, BUFFER_SIZE)) 
	&& ft_strnchr(buffer, '\n') < 0)
	{
	buffer[BUFFER_SIZE + 1] = '\0';
		if (*line == NULL)
			*line = ft_strdup(buffer);
		else
		{
			tmp = malloc(sizeof(char ) * ft_strlen(*line) + ft_strlen(buffer) + 1);
			ft_memccpy(tmp, *line, '\0', BUFFER_SIZE);
			*line = ft_strjoin(tmp, buffer);
		}
	}
	ft_putstr(*line);
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	char *tab;
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

	get_next_line(fd, &tab);

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

