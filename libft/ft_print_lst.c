/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:50:18 by cghanime          #+#    #+#             */
/*   Updated: 2019/01/15 19:06:31 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_lst(t_list *lst)
{
	if (ft_lst_is_empty(lst))
	{
		ft_putstr("Liste vide\n");
		return ;
	}
	while (lst != NULL)
	{
		ft_putstr(lst->content);
		ft_putnbr(lst->content_size);
		lst = lst->next;
	}
	ft_putchar('\n');
}
