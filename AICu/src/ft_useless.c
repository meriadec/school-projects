/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useless.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 07:34:20 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int			st_ok(t_move *move, int n)
{
	return (n == 0 || n == move->player);
}

static int			st_vertical(t_ctx *ctx, t_move *move, int **grid)
{
	int				y;
	int				n;

	y = move->row;
	n = ctx->player;
	while (y < ctx->rows && grid[y][move->col] == n)
		++y;
	return (y < 1);
}

int					ft_useless(t_ctx *ctx, t_move *move, int **grid)
{
	int			score;

	(void) st_ok;
	score = 0;
	if (st_vertical(ctx, move, grid))
		score -= 1000;
	return (score);
}
