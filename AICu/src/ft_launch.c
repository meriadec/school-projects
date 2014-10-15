/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 18:34:03 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_launch(char **av)
{
	t_ctx			*ctx;

	if (ERR == ft_init_term())
		return (ERR);
	ctx = CTX;
	ctx->rows = ft_atoi(av[1]);
	ctx->cols = ft_atoi(av[2]);
	if (ctx->rows >= ROWS_MIN && ctx->cols >= COLS_MIN)
	{
		if (ERR == ft_check_size(ctx))
			return (ERR);
		if (ERR == ft_malloc_grid(ctx))
			return (ERR);
		if (ERR == ft_loop(ctx))
			return (ERR);
	}
	else
		return (ft_err_size());
	return (OK);
}
