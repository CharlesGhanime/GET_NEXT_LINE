/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 19:07:05 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/24 18:47:03 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_is_negative(int n)
{
	char c;

	c = 0;
	if (n >= 0)
	{
		c = 80;
		ft_putchar(c);
	}
	else
	{
		c = 78;
		ft_putchar(c);
	}
}
