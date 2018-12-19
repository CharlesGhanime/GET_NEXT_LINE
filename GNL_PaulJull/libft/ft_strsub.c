/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 05:35:04 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/19 19:52:40 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	count = 0;
	if (!(str = ft_strnew(len)) || !s)
		return (NULL);
	while (count < len)
	{
		str[count] = s[start + count];
		count += 1;
	}
	return (str);
}
