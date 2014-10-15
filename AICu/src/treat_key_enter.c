/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_enter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 16:12:44 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 16:28:13 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					treat_key_enter(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (!ctx->grid[0][ctx->arrow])
	{
		ft_reset_term();
		ctx->player_last = ctx->arrow;
		return (ft_play(ctx, ctx->player_last));
	}
	return (OK);
}
