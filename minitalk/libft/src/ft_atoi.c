/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:47:16 by mpillet           #+#    #+#             */
/*   Updated: 2013/12/12 16:32:26 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*clean(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	return (str);
}

static const char	*set_sign(int *sign, const char *str)
{
	if (str[0] == '-')
	{
		*sign = -1;
		str++;
	}
	else if (str[0] == '+')
	{
		str++;
		*sign = 1;
	}
	else
	{
		*sign = 1;
	}
	return (str);
}

int					ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	str = clean(str);
	str = set_sign(&sign, str);
	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			return (res * sign);
		}
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
