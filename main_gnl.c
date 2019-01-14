/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:02:35 by cghanime          #+#    #+#             */
/*   Updated: 2019/01/14 19:33:42 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int             main(int argc, char **argv)
{
	int				fd;
	char			*line;
	int				ret;

	fd = open("42", O_RDONLY);
	while(get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	return (0);
}
