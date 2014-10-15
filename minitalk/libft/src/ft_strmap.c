/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:41:42 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/30 10:35:39 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		length;
	int		i;
	char	*out;

	out = NULL;
	if (s)
	{
		length = ft_strlen(s);
		i = 0;
		out = (char *) malloc(sizeof(char) * (length + 1));
		if (out)
		{
			while (i < length)
			{
				out[i] = f(s[i]);
				i++;
			}
			out[i] = '\0';
		}
	}
	return (out);
}
