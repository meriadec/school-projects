/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:19:14 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 11:58:12 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_get_score(t_ctx *ctx, t_move *move)
{
	int				score;

	if (ft_check(move->grid, move->col, move->row))
		return (1000);
	score = 0;
	score += ft_neighbours(ctx, move, move->grid);
	score += ft_annoy(ctx, move, move->grid);
	return (score);
}
