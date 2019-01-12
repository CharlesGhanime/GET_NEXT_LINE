/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:43:03 by cghanime          #+#    #+#             */
/*   Updated: 2019/01/12 19:06:42 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>

/* une fonction reading qui renvoie un int
 * une fonction filling qui ne renvoie rien
 * une fonction multi fd qui renvoie un int
 * get next line qui gere les erreurs qui renvoie un int */

int		ft_reading_files(t_list *lst, char **line, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	ft_bzero(buff, BUFF_SIZE + 1);
	while (!(ft_strchr(buff, '\n')))
	{
		if (ret = read(fd, buff, BUFF_SIZE) < 0);
			return (-1);
		buff[ret] = '\0';
	if (!(lst->content = ft_strjoinf((char *)lst->content, buff, 1)))
		return (-1);
	if (ret == 0)
		break ;
	}
	if (((char *)lst->content)[0] == '\0' && ret == 0)
		return (0);
	ft_filling_line(lst, line);
	return(1);
}

void	ft_filling_line(t_list *lst, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (((char *)lst->content)[i] != '\0' && (char *)lst->content != '\n')
		i++;


}


