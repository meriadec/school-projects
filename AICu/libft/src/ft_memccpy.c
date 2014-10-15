/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:08:51 by mpillet           #+#    #+#             */
/*   Updated: 2013/12/13 16:26:04 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) s1)[i] = ((unsigned char *) s2)[i];
		if (((unsigned char *) s1)[i] == (unsigned char) c)
		{
			return ((void *)(((unsigned char *)s1) + i + 1));
		}
		i++;
	}
	return (NULL);
}
