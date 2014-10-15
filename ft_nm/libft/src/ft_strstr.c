/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:22:35 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/24 16:32:36 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	char	*tmp;

	tmp = (char *)s1;
	if (!*s2)
		return ((char *)s1);
	while (*tmp)
	{
		str1 = (char *)tmp;
		str2 = (char *)s2;
		while (*tmp && *str2 && *tmp == *str2)
		{
			tmp++;
			str2++;
		}
		if (!*str2)
			return (str1);
		tmp = str1 + 1;
	}
	return (NULL);
}
