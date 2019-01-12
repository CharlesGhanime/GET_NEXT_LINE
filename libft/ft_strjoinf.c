/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:00:11 by cghanime          #+#    #+#             */
/*   Updated: 2019/01/12 19:01:08 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		s_management(char **new_str, char *s1, char *s2)
{
	if (s1 == NULL)
	{
		if(!(*new_str = ft_strdup(s2)))
			return (-1);
		return (1);
	}
	else if (s2 == NULL)
	{
		if(!(*new_str = ft_strdup(s1)))
			return (-1);
		return (2);
	}
	return (0);
}
char			*ft_strjoinf(char *s1, char *s2, int flag)
{
	char    *tmp;
	char    *new_str;
	int     len_s1;
	int     len_s2;
	if (s_management(&new_str, s1, s2) != 0)
		return (new_str);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	tmp = new_str;
	ft_strncpy(new_str, s1, len_s1);
	ft_strncpy(&new_str[len_s1], s2, len_s2 + 1);
	if (flag == 1 || flag == 3)
		free(s1);
	if (flag == 2 || flag == 3)
		free(s2);
	return (new_str);
}
