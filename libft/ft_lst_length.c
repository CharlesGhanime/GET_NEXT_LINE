/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:09:57 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/06 21:00:45 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_length(t_list *lst)
{
	int size;

	size = 0;
	if (!ft_lst_is_empty(lst))
		while (lst != NULL)
		{
			++size;
			lst = lst->next;
		}
	return (size);
}
