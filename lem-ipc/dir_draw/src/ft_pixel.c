/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 14:57:09 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 15:01:34 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "draw.h"

static void		st_put_pixel(t_ctx *ctx, t_data *d, t_pix p, t_rgb col)
{
	if (d->endian)
	{
		DAT[(SIZ * p.y) + p.x
			* (BPP / 8)] = mlx_get_color_value(MLX, col.r);
		DAT[(SIZ * p.y) + p.x
			* (BPP / 8) + 1] = mlx_get_color_value(MLX, col.g);
		DAT[(SIZ * p.y) + p.x
			* (BPP / 8) + 2] = mlx_get_color_value(MLX, col.b);
	}
	else
	{
		DAT[(SIZ * p.y) + p.x
			* (BPP / 8)] = mlx_get_color_value(MLX, col.b);
		DAT[(SIZ * p.y) + p.x
			* (BPP / 8) + 1] = mlx_get_color_value(MLX, col.g);
		DAT[(SIZ * p.y) + p.x
			* (BPP / 8) + 2] = mlx_get_color_value(MLX, col.r);
	}
}

void			ft_pixel(t_ctx *ctx, t_pix p, t_rgb col)
{
	t_data		d;

	d.data_add = mlx_get_data_addr(IMG, &d.bpp, &d.size, &d.endian);
	st_put_pixel(ctx, &d, p, col);
}
