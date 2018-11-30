/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:38:06 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/29 18:53:42 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef __list_h__
#define __list_h__

/*DEFINITION DE LA STRUCTURE*/

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
/******************************************************************************/
/*FT_PUTCHAR.C*/
/******************************************************************************/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/******************************************************************************/
/*FT_PUTSTR.C*/
/******************************************************************************/
void	ft_putstr(char const *s)
{
	while (s && *s)
		ft_putchar(*s++);
}

/******************************************************************************/
/*ADD_LINK.C*/
/******************************************************************************/
t_list	*add_link(t_list *list, char *str)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->str = str;
		tmp->next = list;
	}
	return (tmp);
}

/******************************************************************************/
/*PRINT_LIST.C*/
/******************************************************************************/
void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->str);
		list = list->next;
	}
}

/******************************************************************************/
/* AUTRE MANIERE D'ECRIRE ADD_LINK*/
/******************************************************************************/

int		addd_link(t_list **list, char *str)
{
	*list = malloc(sizeof(t_list));
	return(0);
}
/******************************************************************************/
/*INT MAIN.C*/
/******************************************************************************/
int		main(void)
{
	t_list	*list;

	list = NULL;
	addd_link(&list, "titi\n");
	list = add_link(list, "toto\n");
	list = add_link(list, "tata\n");
	list = add_link(list, "tutu\n");
	print_list(list);
	return (0);
}
