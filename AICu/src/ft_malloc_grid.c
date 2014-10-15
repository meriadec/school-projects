/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:28:45 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 12:53:54 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "aicu.h"

int					ft_malloc_grid(t_ctx *ctx)
{
	int				i;
	int				y;

	ft_putendl("Loading grid...");
	if (!(ctx->grid = (int **) malloc(sizeof(int *) * ctx->rows)))
		return (ft_error("Can't malloc 'ctx->grid'"));
	i = 0;
	while (i < ctx->rows)
	{
		if (!(ctx->grid[i] = (int *) malloc(sizeof(int) * ctx->cols)))
			return (ft_error("Can't malloc 'ctx->grid[i]'"));
		y = 0;
		while (y < ctx->cols)
		{
			ctx->grid[i][y] = 0;
			++y;
		}
		++i;
	}
	ft_putendl("Done !");
	return (OK);
}
