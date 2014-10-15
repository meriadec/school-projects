/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:56:12 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/01 15:02:22 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_multijoin(int count, ...)
{
	va_list		ap;
	char		*res;
	char		*tmp;

	res = NULL;
	va_start(ap, count);
	res = ft_strdup(va_arg(ap, char *));
	while (count > 0)
	{
		tmp = res;
		res = ft_strjoin(tmp, va_arg(ap, char *));
		free(tmp);
		--count;
	}
	va_end(ap);
	return (res);
}
