/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:04:22 by cghanime          #+#    #+#             */
/*   Updated: 2019/01/15 18:50:16 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 10

int		get_next_line(const int fd, char **line);
t_list	*ft_multi_fd(t_list *lst, int fd);
void	ft_filling_line(t_list *lst, char **line);
int		ft_reading_files(t_list *lst, char **line, int fd);

#endif
