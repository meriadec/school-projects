/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:16:22 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 08:39:58 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int			st_get_score(t_ctx *ctx, int col)
{
	t_move			*move;
	int				ret;
	int				row;

	row = ft_play(ctx, col);
	ft_unplay(ctx, col);
	if (NULL == (move = ft_move_new(TYPE_LEAF, ctx->grid, row, col)))
		return (ft_error("Problem mallocing new t_move"));
	if (-1 == (ret = ft_minmax(ctx, move)))
		return (-1);
	ft_del_grid(&move->grid);
	ft_memdel((void **) &move);
	return (ret);
}

static int			st_calc(t_ctx *ctx, int *res)
{
	int				i;
	int				ret;
	int				score;

	i = 0;
	score = -1;
	while (i < ctx->cols)
	{
		if (!ctx->grid[0][i])
		{
			if (ERR == (ret = st_get_score(ctx, i)))
				return (ft_error("Can't determinate probability"));
			if (ret > score || *res == -1)
			{
				*res = i;
				score = ret;
			}
			else if (ret == -1)
				return (ERR);
		}
		++i;
	}
	return (OK);
}

int					ft_ia_play(t_ctx *ctx)
{
	int				res;

	if (ft_is_empty(ctx->grid))
	{
		ctx->last = ctx->cols / 2;
		return (ft_play(ctx, ctx->last));
	}
	res = -1;
	if (ERR == st_calc(ctx, &res))
		return (ERR);
	ctx->last = res;
	return (ft_play(ctx, res));
}
