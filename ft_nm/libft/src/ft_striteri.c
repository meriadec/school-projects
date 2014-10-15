/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:38:12 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/30 10:31:09 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	length;
	unsigned int	i;

	if (s && f)
	{
		length = ft_strlen(s);
		i = 0;
		while (i < length)
		{
			f(i, &(s[i]));
			i++;
		}
	}
}
