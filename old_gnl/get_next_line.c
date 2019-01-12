/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:15:01 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/18 16:50:10 by cghanime         ###   ########.fr       */
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
** memccpy jusqu'a '\n' dans buff et strncpy le reste dans tmp (content)
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

void	ft_filling_line(t_list *lst, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((char *)lst->content[i] != '\n' && ((char *)lst->content)[i] != '\0')
		i++;
	if (i == 0)
		return ;
	*line = ft_strnew(i);

}

int		get_next_line(const int fd, char **line)
{
	int ret;
	int i;
	char buff[BUFF_SIZE + 1];
	static t_list *lst;
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (lst)
	{
		
	}

	return ();
}
int		main()
{
	
	return (0);
}
