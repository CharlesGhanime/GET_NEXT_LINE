/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_retry.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:15:01 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/18 01:45:07 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include "libft/libft.h"

int		get_next_line(const int fd, char **line)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	t_list	*lst;
	char	*tmp;
	int		endl;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0 && !ft_strchr(buffer, '\n'))
	{
		buffer[ret] = '\0';
		tmp = lst->content;
		lst->content = ft_strjoin(lst->content, buffer);
		ft_strdel(&tmp);
	}
	if (ret == -1 || !*(tmp = lst->content))
		return (ret = -1 ? -1 : 0);
	if ((endl = (ft_strchr(lst->content, '\n') > 0)))
		*line = ft_strsub(lst->content, 0, ft_strchr(lst->content, '\n')
		- (char *)(lst->content));
	*line = ft_strdup(lst->content);
	lst->content = ft_strsub(lst->content, (unsigned int)(ft_strlen(*line)
	+ endl), (size_t)(ft_strlen(lst->content) - (ft_strlen(*line) + endl)));
	ft_strdel(&tmp);
	return (!(!lst->content && !ft_strlen(*line)));
}

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

		get_next_line(fd, &tab);

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
