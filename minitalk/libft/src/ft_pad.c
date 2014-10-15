/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 18:10:30 by mpillet           #+#    #+#             */
/*   Updated: 2013/12/20 15:34:26 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_lpad(char *input, size_t len, char c)
{
	char		*res;
	size_t		max;
	size_t		i;

	if (!(res = (char *) malloc(sizeof(char) * (len + 1))))
		exit(-1);
	max = len - ft_strlen(input);
	i = 0;
	while (i < max)
	{
		res[i] = c;
		++i;
	}
	res = ft_strcat(res, input);
	return (res);
}

char	*ft_rpad(char *input, size_t len, char c)
{
	char		*res;
	size_t		i;

	if (!(res = (char *) malloc(sizeof(char) * (len + 1))))
		exit(-1);
	res = ft_strcat(res, input);
	i = ft_strlen(input);
	while (i < len)
	{
		res[i] = c;
		++i;
	}
	return (res);
}
