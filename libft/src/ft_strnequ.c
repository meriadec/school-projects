/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:53:52 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/30 10:33:01 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		cmp;

	if (s1 && s2)
	{
		cmp = ft_strncmp(s1, s2, n);
		if (cmp == 0)
		{
			return (1);
		}
	}
	return (0);
}
