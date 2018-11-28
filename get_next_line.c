/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:41:11 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/28 20:34:48 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 1

int main(int argc, char **argv)
{
	int fd;
	int read_return;
	char buffer[BUFFER_SIZE + 1];

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("Open() failed");
			return (1);
		}
		while ((read_return = read (fd, buffer, BUFFER_SIZE)) != '\n')
		{
			//buffer[read_return] = '\0';
			ft_putstr(buffer);
			//ft_putnbr(read_return);
		}
		if (close(fd) == -1)
		{
			ft_putstr("Close() failed");
			return (1);
		}
	}
	else
		ft_putstr("Too few arguments");
	return (0);
}

