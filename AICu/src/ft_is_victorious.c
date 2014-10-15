/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_victorious.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 12:20:31 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int			st_horizontal(t_ctx *ctx, int col, int row)
{
	int				count;
	int				x;
	int				n;

	count = 0;
	n = ctx->winner;
	x = col + 1;
	while (x < ctx->cols && ctx->grid[row][x] == n)
	{
		++x;
		++count;
	}
	x = col - 1;
	while (x >= 0 && ctx->grid[row][x] == n)
	{
		--x;
		++count;
	}
	return (count >= 3);
}

static int			st_vertical(t_ctx *ctx, int col, int row)
{
	int				count;
	int				y;
	int				n;

	count = 0;
	n = ctx->winner;
	y = row + 1;
	while (y < ctx->rows && ctx->grid[y][col] == n)
	{
		++y;
		++count;
	}
	y = row - 1;
	while (y >= 0 && ctx->grid[y][col] == n)
	{
		--y;
		++count;
	}
	return (count >= 3);
}

static int			st_diagonal_1(t_ctx *ctx, int col, int row)
{
	int				count;
	int				y;
	int				x;
	int				n;

	count = 0;
	n = ctx->winner;
	y = row + 1;
	x = col + 1;
	while (y < ctx->rows && x < ctx->cols && ctx->grid[y][x] == n)
	{
		++y;
		++x;
		++count;
	}
	y = row - 1;
	x = col - 1;
	while (y >= 0 && x >= 0 && ctx->grid[y][x] == n)
	{
		--y;
		--x;
		++count;
	}
	return (count >= 3);
}

static int			st_diagonal_2(t_ctx *ctx, int col, int row)
{
	int				count;
	int				y;
	int				x;
	int				n;

	count = 0;
	n = ctx->winner;
	y = row + 1;
	x = col - 1;
	while (y < ctx->rows && x >= 0 && ctx->grid[y][x] == n)
	{
		++y;
		--x;
		++count;
	}
	y = row - 1;
	x = col + 1;
	while (y >= 0 && x < ctx->cols && ctx->grid[y][x] == n)
	{
		--y;
		++x;
		++count;
	}
	return (count >= 3);
}

int					ft_is_victorious(t_ctx *ctx, int col, int row)
{
	if (ctx->grid[row][col] != ctx->winner)
		return (FALSE);
	return (st_vertical(ctx, col, row) || st_horizontal(ctx, col, row)
			|| st_diagonal_1(ctx, col, row) || st_diagonal_2(ctx, col, row));
}
