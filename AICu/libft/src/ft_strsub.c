/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:56:50 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/25 11:02:35 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	char		*out;

	length = ft_strlen(s);
	out = NULL;
	if ((start + len) <= length)
	{
		out = (char *) malloc(sizeof(char) * (len + 1));
		if (out)
		{
			out = ft_strncpy(out, s + start, len);
			out[len] = '\0';
		}
	}
	return (out);
}
