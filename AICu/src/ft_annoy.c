/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annoy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 05:26:08 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int			st_horizontal(t_ctx *ctx, t_move *move, int **grid)
{
	int				count;
	int				x;
	int				n;

	count = 0;
	n = (move->player == 1) ? 2 : 1;
	x = move->col + 1;
	while (x < ctx->cols && grid[move->row][x] == n)
	{
		++x;
		count += 6;
	}
	x = move->col - 1;
	while (x >= 0 && grid[move->row][x] == n)
	{
		--x;
		count += 6;
	}
	return (count == 18 ? 100 : count);
}

static int			st_vertical(t_ctx *ctx, t_move *move, int **grid)
{
	int				count;
	int				y;
	int				n;

	count = 0;
	n = (move->player == 1) ? 2 : 1;
	y = move->row + 1;
	while (y < ctx->rows && grid[y][move->col] == n)
	{
		++y;
		count += 6;
	}
	y = move->row - 1;
	while (y >= 0 && grid[y][move->col] == n)
	{
		--y;
		count += 6;
	}
	return (count == 18 ? 100 : count);
}

static int			st_diagonal_1(t_ctx *ctx, t_move *move, int **grid)
{
	int				count;
	int				y;
	int				x;
	int				n;

	count = 0;
	n = (move->player == 1) ? 2 : 1;
	y = move->row + 1;
	x = move->col + 1;
	while (y < ctx->rows && x < ctx->cols && grid[y][x] == n)
	{
		++y;
		++x;
		count += 6;
	}
	y = move->row - 1;
	x = move->col - 1;
	while (y >= 0 && x >= 0 && grid[y][x] == n)
	{
		--y;
		--x;
		count += 6;
	}
	return (count == 18 ? 100 : count);
}

static int			st_diagonal_2(t_ctx *ctx, t_move *move, int **grid)
{
	int				count;
	int				y;
	int				x;
	int				n;

	count = 0;
	n = (move->player == 1) ? 2 : 1;
	y = move->row + 1;
	x = move->col - 1;
	while (y < ctx->rows && x >= 0 && grid[y][x] == n)
	{
		++y;
		--x;
		count += 6;
	}
	y = move->row - 1;
	x = move->col + 1;
	while (y >= 0 && x < ctx->cols && grid[y][x] == n)
	{
		--y;
		++x;
		count += 6;
	}
	return (count == 18 ? 100 : count);
}

int					ft_annoy(t_ctx *ctx, t_move *move, int **grid)
{
	int				count;

	count = 0;
	count += st_vertical(ctx, move, grid);
	count += st_horizontal(ctx, move, grid);
	count += st_diagonal_1(ctx, move, grid);
	count += st_diagonal_2(ctx, move, grid);
	return (count);
}
