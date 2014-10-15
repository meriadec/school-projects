/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:23:53 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/05 12:46:21 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	char	*out;

	out = NULL;
	if (s1 && !s2)
		out = ft_strdup(s1);
	else if (!s1 && s2)
		out = ft_strdup(s2);
	else if (s1 && s2)
	{
		length = ft_strlen(s1) + ft_strlen(s2);
		out = (char *) malloc(sizeof(char) * (length + 1));
		if (out)
		{
			ft_strcpy(out, s1);
			ft_strcat(out, s2);
		}
	}
	return (out);
}
