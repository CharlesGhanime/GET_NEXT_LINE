/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:41:11 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/02 16:48:52 by cghanime         ###   ########.fr       */
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

	rest = NULL;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while ((read_return = read(fd, buffer, BUFFER_SIZE)) 
	&& ft_strnchr(buffer, '\n') < 0)
	{
	buffer[read_return] = '\0';
		if (rest == NULL)
			rest = ft_strdup(buffer);
		else
		{
			tmp = malloc(sizeof(char ) * ft_strlen(rest) + ft_strlen(buffer) + 1);
			ft_strcpy(tmp, rest);
			ft_strcat(tmp, buffer);
			rest = tmp;
		}
	}
	*line = rest;
	ft_putstr(rest);
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

