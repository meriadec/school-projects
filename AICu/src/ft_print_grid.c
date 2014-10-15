/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:33:55 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 18:08:26 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include "aicu.h"

static void			st_print_cell(int cell, int first, int last, int red)
{
	if (first)
		ft_putstr(" \033[7;39m \033[0m ");
	else
		ft_putchar(' ');
	if (0 == cell)
		ft_putstr("\033[0;30m◌\033[0m");
	else
	{
		if (red)
			ft_putstr("\033[0;31m◉\033[0m");
		else
		{
			if (2 == cell)
				ft_putstr("\033[0;33m◉\033[0m");
			else if (1 == cell)
				ft_putstr("\033[0;36m◉\033[0m");
		}
	}
	if (last)
		ft_putstr(" \033[7;39m \033[0m ");
}

static void			st_print_nums(int cols, int i, int n)
{
	ft_putstr(" \033[7;39m  ");
	while (i < cols)
	{
		ft_putstr("  ");
		++i;
		++n;
	}
	ft_putstr("\033[7;0m");
	ft_print_foots(cols);
}

static void			st_print_floor(int cols)
{
	int				i;

	i = 0;
	st_print_nums(cols, 0, 0);
	ft_putchar('\n');
}

static void			st_print_end(t_ctx *ctx)
{
	int				pad;

	st_print_floor(ctx->cols);
	if (!ctx->victory)
	{
		pad = (ctx->cols * 2 + 4) / 2 - 7;
		ft_center(pad, "\033[7;39m   ⬄   \033[0;0m  \033[1;32mMove\033[1;0m");
		ft_center(pad, "\033[7;39m ENTER \033[0;0m  \033[1;32mPlay\033[1;0m");
		ft_center(pad, "\033[7;39m   Q   \033[0;0m  \033[1;32mExit\033[1;0m");
	}
}

void				ft_print_grid(int **grid)
{
	int				x;
	int				y;
	t_ctx			*ctx;

	ctx = CTX;
	ft_raw_term();
	tputs(tgetstr("cl", NULL), 1, ft_putput);
	ft_reset_term();
	ft_ascii();
	y = 0;
	while (y < ctx->rows)
	{
		x = 0;
		while (x < ctx->cols)
		{
			if (ctx->victory && ft_is_victorious(ctx, x, y))
				st_print_cell(grid[y][x], x == 0, x == ctx->cols - 1, 1);
			else
				st_print_cell(grid[y][x], x == 0, x == ctx->cols - 1, 0);
			++x;
		}
		ft_putchar('\n');
		++y;
	}
	st_print_end(ctx);
}
