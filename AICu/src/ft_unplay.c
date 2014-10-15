/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unplay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:35:42 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/08 19:37:42 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_unplay(t_ctx *ctx, int col)
{
	int				row;

	row = 0;
	while (!ctx->grid[row][col])
		++row;
	ctx->grid[row][col] = 0;
	++ctx->pieces;
	return (OK);
}
