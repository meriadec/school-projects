/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ctx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:39:16 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 17:28:34 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "aicu.h"

static void			st_set_defaults(t_ctx *ctx)
{
	ctx->cols = -1;
	ctx->rows = -1;
	ctx->player = -1;
	ctx->grid = NULL;
	ctx->winner = 0;
	ctx->last = -1;
	ctx->victory = 0;
	ctx->player_last = -1;
	ctx->pieces = NB_PIECES;
	ctx->arrow = -1;
}

t_ctx				*ft_get_ctx(void)
{
	static t_ctx	*ctx = NULL;

	if (NULL == ctx)
	{
		if (!(ctx = (t_ctx *) malloc(sizeof(t_ctx))))
			ft_error("Can't malloc 'ctx'");
		st_set_defaults(ctx);
	}
	return (ctx);
}
