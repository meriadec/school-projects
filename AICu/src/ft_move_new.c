/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:31:38 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 01:29:57 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "aicu.h"

t_move				*ft_move_new(int type, int **grid, int row, int col)
{
	t_move			*move;
	t_ctx			*ctx;

	ctx = CTX;
	if (!(move = (t_move *) malloc(sizeof(t_move))))
	{
		ft_error("Can't malloc 'move'");
		return (NULL);
	}
	move->cost = 0;
	move->type = type;
	if (type == TYPE_OPP)
		move->player = ctx->player == 1 ? 2 : 1;
	else
		move->player = ctx->player;
	move->childs = NULL;
	move->row = row;
	move->col = col;
	move->grid = ft_dup_grid(grid);
	return (move);
}
