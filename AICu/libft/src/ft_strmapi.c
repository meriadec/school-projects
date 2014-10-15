/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:48:43 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/27 14:45:56 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	length;
	unsigned int	i;
	char			*out;

	length = ft_strlen(s);
	i = 0;
	out = (char *) malloc(sizeof(char) * (length + 1));
	if (out)
	{
		while (i < length)
		{
			out[i] = f(i, s[i]);
			i++;
		}
		out[i] = '\0';
	}
	return (out);
}
