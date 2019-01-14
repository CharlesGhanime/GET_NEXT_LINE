/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_back_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:50:13 by cghanime          #+#    #+#             */
/*   Updated: 2019/01/14 17:45:54 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin_lst, void *content, size_t content_size)
{
	t_list *node;
	t_list *head;
	t_list *buff;

	if (!begin_lst)
		return ;
	buff = *begin_lst; //stockage du dereferencement 
	head = *begin_lst;
	if (!(node = ft_lstnew((const void *)content, content_size)))
		return ;
	if (!buff)
		*begin_lst = node;
	else
	{
		while (buff->next)
			buff = buff->next;
		buff->next = node;
	}
	if (head)
		*begin_lst = head;
}

/*
int main()
{
	t_list*lst;
	t_list*new_map;

	lst = ft_lstnew(NULL, si		zeof("a"));
	ft_lst_push_back(&lst, "salut", sizeof("salut"));
	ft_lst_push_back(&lst, "chocolat", sizeof("chocolat"));
	ft_lst_push_back(&lst, "tortue", sizeof("tortue"));
	ft_lst_push_back(&lst, "je ne sais pas si il y a de bonne ou de mauvaise situation", sizeof("je ne sais pas si il y a de bonne ou de mauvaise situation"));
	ft_lst_push_back(&lst, "il a pas dit bonjour, du coup ...", sizeof("il a pas dit bonjour, du coup ..."));

	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}
*/
