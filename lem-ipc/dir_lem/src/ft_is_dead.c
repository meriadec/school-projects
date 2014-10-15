/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 19:28:11 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:22:44 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static int					st_check(int num, int n[], int team)
{
	int						i;
	int						nb;

	i = 0;
	nb = 0;
	if (num == team)
		return (0);
	while (i < 8)
	{
		if (n[i] && n[i] == num)
			++nb;
		++i;
	}
	return (nb >= 2);
}

static void					st_set_vals(t_ctx *ctx, int n[8])
{
	n[0] = POSY > 0 ? MAP[POSY - 1][POSX] : 0;
	n[1] = POSX < W - 1 ? MAP[POSY][POSX + 1] : 0;
	n[2] = POSY < H - 1 ? MAP[POSY + 1][POSX] : 0;
	n[3] = POSX > 0 ? MAP[POSY][POSX - 1] : 0;
	n[4] = POSY > 0 && POSX > 0 ? MAP[POSY - 1][POSX - 1] : 0;
	n[5] = POSX < W - 1 && POSY < H - 1 ? MAP[POSY + 1][POSX + 1] : 0;
	n[6] = POSY < H - 1 && POSX > 0 ? MAP[POSY + 1][POSX - 1] : 0;
	n[7] = POSX < W - 1 && POSY > 0 ? MAP[POSY - 1][POSX + 1] : 0;
}

int							ft_is_dead(void)
{
	t_ctx					*ctx;
	int						n[8];

	ctx = ft_ctx();
	sem_read_start();
	st_set_vals(ctx, n);
	if (st_check(n[0], n, ctx->team)
			|| st_check(n[1], n, ctx->team)
			|| st_check(n[2], n, ctx->team)
			|| st_check(n[3], n, ctx->team)
			|| st_check(n[4], n, ctx->team)
			|| st_check(n[5], n, ctx->team)
			|| st_check(n[6], n, ctx->team)
			|| st_check(n[7], n, ctx->team))
	{
		return (1);
		sem_read_end();
	}
	sem_read_end();
	return (0);
}
