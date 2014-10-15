/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 01:22:02 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_is_empty(int **grid)
{
	t_ctx			*ctx;
	int				x;
	int				y;

	ctx = CTX;
	y = 0;
	while (y < ctx->rows)
	{
		x = 0;
		while (x < ctx->cols)
		{
			if (grid[y][x])
				return (FALSE);
			++x;
		}
		ft_putchar('\n');
		++y;
	}
	return (TRUE);
}
