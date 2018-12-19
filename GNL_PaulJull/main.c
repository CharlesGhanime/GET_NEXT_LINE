/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:22:48 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/19 22:32:11 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;
	int		c;

	fd = 0;
	line = NULL;
	c = 10;
	if (argc > 1)
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (-1);
	ret = 1;
	i = 1;
	while (c-- > 1)
	{
		printf("line = %s\n", line);
		printf("return = %d\n", ret);
		free(line);
		line = NULL;
	}
	printf("final return = %d\n", ret);
	close(fd);
	return (0);
}
