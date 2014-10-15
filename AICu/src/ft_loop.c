/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:04:14 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 18:12:13 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "aicu.h"

static int			st_choose_player(void)
{
	srand(time(0));
	return (rand() % 2 + 1);
}

int					ft_loop(t_ctx *ctx)
{
	ctx->player = st_choose_player();
	ft_print_grid(ctx->grid);
	while (!ft_stop(ctx))
	{
		if (ctx->player == 1)
		{
			if (ERR == ft_player_play(ctx))
				return (ERR);
		}
		else
		{
			if (ERR == ft_ia_play(ctx))
			{
				ft_error("IA failed...");
				return (ERR);
			}
		}
		ctx->player = ctx->player == 1 ? 2 : 1;
		ft_print_grid(ctx->grid);
	}
	return (ft_win(ctx));
}
