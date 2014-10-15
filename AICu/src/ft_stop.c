/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:07:19 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 18:12:31 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_stop(t_ctx *ctx)
{
	int				x;
	int				y;

	if (!ctx->pieces)
	{
		ctx->winner = 3;
		return (TRUE);
	}
	y = 0;
	while (y < ctx->rows)
	{
		x = 0;
		while (x < ctx->cols)
		{
			if (ft_check(ctx->grid, x, y))
				return (TRUE);
			++x;
		}
		++y;
	}
	return (FALSE);
}
