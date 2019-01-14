/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:04:22 by cghanime          #+#    #+#             */
/*   Updated: 2019/01/14 19:30:23 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);
t_list	*fd_management(t_list *lst, int fd);
void	fill_line(t_list *lst, char **line);
int		ft_read(t_list *lst, char **line, int fd);

# endif
