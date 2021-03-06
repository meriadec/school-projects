/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:53:20 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/12 17:06:19 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"

t_ctx						*ft_ctx(void)
{
	static t_ctx			*ctx = NULL;

	if (NULL == ctx)
	{
		if (!(ctx = (t_ctx *)malloc(sizeof(t_ctx))))
			ft_error("Can't malloc 'ctx'");
	}
	return (ctx);
}
