/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:41:11 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/01 21:17:15 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int read_return;
	char buffer[BUFFER_SIZE + 1];
	char *tmp;
	char *gnl;

	gnl = NULL;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while ((read_return = read(fd, buffer, BUFFER_SIZE)) 
	&& ft_strnchr(buffer, '\n') < 0)
	{
	buffer[read_return] = '\0';
		if (gnl == NULL)
			gnl = ft_strdup(buffer);
		else
		{
			tmp = malloc(sizeof(char ) * ft_strlen(gnl) + BUFFER_SIZE + 1);
			ft_strcpy(tmp, gnl);
			printf("1.Retour de strcpy\n");
			printf("1.%s\n", ft_strcpy(tmp, gnl));
			ft_strjoin(tmp, buffer);
			printf("2.Retour de strjoin\n");
			printf("2.%s\n", ft_strcat(tmp, buffer));
			gnl = tmp;
			printf("3. Contenu de gnl\n");
			printf("3.%s\n", gnl);
		}
	}
	*line = gnl;
	//ft_putstr(gnl);
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

