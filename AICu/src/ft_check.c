/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:56:10 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 04:46:38 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int			st_check_vertical(int **grid, int x, int y)
{
	int				n;

	n = G(x, y);
	return (n == G(x, y + 1) && n == G(x, y + 2) && n == G(x, y + 3));
}

static int			st_check_horizontal(int **grid, int x, int y)
{
	int				n;

	n = G(x, y);
	return (n == G(x + 1, y) && n == G(x + 2, y) && n == G(x + 3, y));
}

static int			st_check_diagonals_1(t_ctx *ctx, int **grid, int x, int y)
{
	int				n;

	n = G(x, y);
	if (x + 3 < ctx->cols && y + 3 < ctx->rows)
	{
		if (n == G(x + 1, y + 1)
				&& n == G(x + 2, y + 2)
				&& n == G(x + 3, y + 3))
			return (TRUE);
	}
	if (x - 3 >= 0 && y - 3 >= 0)
	{
		if (n == G(x - 1, y - 1)
				&& n == G(x - 2, y - 2)
				&& n == G(x - 3, y - 3))
			return (TRUE);
	}
	return (FALSE);
}

static int			st_check_diagonals_2(t_ctx *ctx, int **grid, int x, int y)
{
	int				n;

	n = G(x, y);
	if (x + 3 < ctx->cols && y - 3 >= 0)
	{
		if (n == G(x + 1, y - 1)
				&& n == G(x + 2, y - 2)
				&& n == G(x + 3, y - 3))
			return (TRUE);
	}
	if (x - 3 >= 0 && y + 3 < ctx->rows)
	{
		if (n == G(x - 1, y + 1)
				&& n == G(x - 2, y + 2)
				&& n == G(x - 3, y + 3))
			return (TRUE);
	}
	return (FALSE);
}

int					ft_check(int **grid, int x, int y)
{
	t_ctx			*ctx;

	ctx = CTX;
	ctx->winner = grid[y][x];
	if (ctx->winner)
	{
		if (x + 3 < ctx->cols)
		{
			if (st_check_horizontal(ctx->grid, x, y))
				return (TRUE);
		}
		if (y + 3 < ctx->rows)
		{
			if (st_check_vertical(ctx->grid, x, y))
				return (TRUE);
		}
		if (st_check_diagonals_1(ctx, ctx->grid, x, y))
			return (TRUE);
		if (st_check_diagonals_2(ctx, ctx->grid, x, y))
			return (TRUE);
		ctx->winner = 0;
	}
	return (FALSE);
}
