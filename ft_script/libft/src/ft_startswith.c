/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:24:07 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/28 12:26:43 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_startswith(const char *str, const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && str[i] == s[i])
	{
		i++;
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}