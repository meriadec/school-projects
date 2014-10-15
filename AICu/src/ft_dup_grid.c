/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 17:40:53 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/08 17:50:13 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "aicu.h"

int					**ft_dup_grid(int **grid)
{
	t_ctx			*ctx;
	int				**grid_new;
	int				i;
	int				y;

	ctx = CTX;
	if (!(grid_new = (int **) malloc(sizeof(int *) * ctx->rows)))
		return (NULL);
	i = 0;
	while (i < ctx->rows)
	{
		if (!(grid_new[i] = (int *) malloc(sizeof(int) * ctx->cols)))
			return (NULL);
		y = 0;
		while (y < ctx->cols)
		{
			grid_new[i][y] = grid[i][y];
			++y;
		}
		++i;
	}
	return (grid_new);
}
