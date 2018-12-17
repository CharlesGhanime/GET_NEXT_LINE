/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:15:01 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/17 03:18:43 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

/*
** check open :
** si fd == -1 return (-1)
** sinon return (fd);
** lecture :
** 3 cas de lectures : 
**
** (checker si tmp est vide ou 
** non et si il ne l'est pas lire tmp et stocker dans line)
**
** 1er cas : si '\n' avant la fin de buffer
** memccpy jusqu'a '\n' dans buff et stocker le reste dans tmp (content)
**
** 2e cas : si '\n' pile a la fin du buffer
** memccpy jusqu'a '\n'
**
** 3e cas : pas de '\n' dans le buffer
** memcpy la longueur de buff (BUFF_SIZE)
**
** gestion des fd : quand je recois un fd valide je dois 
** -> checker si lst existe
** la creer si elle n'existe pas
** la parcourir : si fd existe je break
** sinon si fd n'existe pas je creer un nouveau maillon avec fd dedans
*/



int		ft_check(const int fd)
{
	if (fd == -1)
	{
		ft_putstr("open failed");
		return (-1);
	}
	return (fd);
}
t_list	*ft_filling_list(const int fd, t_list *lst)
{
	int		read_return;
	char	buff[BUFF_SIZE + 1];

	while (read_return = read(fd, buff, BUFF_SIZE) > 0)
	{
		if (!lst)
		{
			if (tmp)
			{
				lst = ft_lstnew(NULL, 0);
				lst->content = ft_memccpy(lst->content, tmp, '\n', BUFF_SIZE);
				lst->content_size = fd;
			}
			else
			lst = ft_lstnew(NULL, 0);
			ft_memccpy(lst->content, buff, '\n', BUFF_SIZE);
			lst->content_size = fd;
			buff[i] = '\0';
			while (buff[i + 1] != '\0')
				ft_strcpy(tmp, buff);
		}
		while (lst)
		{
			if (lst->content_size == fd)
				break;
			lst = lst->next;
		}
	}
	return (lst);
}

int		main()
{
	
	return (0);
}
