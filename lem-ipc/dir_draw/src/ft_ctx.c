/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:24:36 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 13:04:23 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "draw.h"

t_ctx						*ft_ctx(void)
{
	static t_ctx			*ctx = NULL;

	if (NULL == ctx)
	{
		if (!(ctx = (t_ctx *)malloc(sizeof(t_ctx))))
			ft_error_exit("Can't malloc 'ctx'");
	}
	return (ctx);
}
