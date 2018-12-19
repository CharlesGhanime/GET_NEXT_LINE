/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_listes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:58:31 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/06 22:37:33 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	t_list *mylist;

	mylist = ft_lstnew("ma bite", sizeof("ma bite"));
//	ft_lst_push_back(mylist, "ta pute", sizeof("ta pute"));
	if (ft_lst_is_empty(mylist))
		ft_putstr("List is empty\n");
	else
		ft_putstr("List has elements declared\n");
//	printf("List length is : %d\n", ft_lst_length(mylist));
	ft_putstr("List length is : ");
	ft_putnbr(ft_lst_length(mylist));
	return (0);
}
