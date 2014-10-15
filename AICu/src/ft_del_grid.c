/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 01:59:33 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_del_grid(int ***grid)
{
	t_ctx			*ctx;
	int				y;

	ctx = CTX;
	y = 0;
	while (y < ctx->rows)
	{
		ft_memdel((void **) &((*grid)[y]));
		++y;
	}
	ft_memdel((void **) grid);
	return (OK);
}
