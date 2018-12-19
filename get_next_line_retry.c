/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_retry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:15:01 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/18 21:11:54 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*c[2147483647];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		b;
	int			endl;

	if (fd < 0 || (!c[fd] && !(c[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(c[fd], '\n') && (b = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[b] = '\0';
		tmp = c[fd];
		c[fd] = ft_strjoin(c[fd], buffer);
		ft_strdel(&tmp);
	}
	if (b == -1 || !*(tmp = c[fd]))
		return (b == -1 ? -1 : 0);
	if ((endl = (ft_strchr(c[fd], '\n') > 0)))
		*line = ft_strsub(c[fd], 0, ft_strchr(c[fd], '\n') - c[fd]);
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + endl)));
	ft_strdel(&tmp);
	return (!(!c[fd] && !ft_strlen(*line)));
}

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
