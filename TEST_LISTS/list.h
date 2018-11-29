/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:20:30 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/29 18:25:41 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __list_h__
#define __list_h__

typedef struct s_list t_list;
struct s_list
{
	char	*str;
	t_list	*next;
};

t_list	*add_link(t_list *list, char *str);
int		addd_link(t_list **list, char *str);
void	print_list(t_list *list);
void	ft_putstr(char const *s);

#endif

