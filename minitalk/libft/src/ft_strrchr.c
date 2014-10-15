/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:37:09 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/27 12:23:53 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;

	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == (char) c)
		{
			return (&(((char *) s)[length]));
		}
		length--;
	}
	return (NULL);
}
