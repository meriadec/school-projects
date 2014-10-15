/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:38:33 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 00:01:04 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_play(t_ctx *ctx, int col)
{
	int				row;

	row = ctx->rows - 1;
	while (ctx->grid[row][col])
		--row;
	ctx->grid[row][col] = ctx->player;
	--ctx->pieces;
	return (row);
}
