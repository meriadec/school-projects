/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 15:17:18 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 17:17:25 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "draw.h"

static t_rgb				st_lighten(t_rgb color)
{
	t_rgb					lighten;

	lighten.r = color.r + 40;
	lighten.g = color.g + 40;
	lighten.b = color.b + 40;
	return (lighten);
}

static int					st_is_light(t_pix pix, int x, int y, int team)
{
	if (pix.x == OFFSET + 1
			|| pix.x == WIDTH - OFFSET
			|| pix.y == OFFSET + 1
			|| pix.y == HEIGHT - OFFSET
			|| (team && (x == 0 || y == 0 || x == 9 || y == 9)))
		return (TRUE);
	return (FALSE);
}

void						ft_draw_cell(int team, int posx, int posy)
{
	t_ctx					*ctx;
	t_pix					pix;
	t_rgb					color;
	int						x;
	int						y;

	ctx = ft_ctx();
	pix.y = OFFSET + (posy * 10);
	y = -1;
	color = ft_get_color_by_team(team);
	while (++y < 10)
	{
		x = -1;
		++pix.y;
		pix.x = OFFSET + (posx * 10);
		while (++x < 10)
		{
			++pix.x;
			if (st_is_light(pix, x, y, team))
				ft_pixel(ctx, pix, st_lighten(color));
			else
				ft_pixel(ctx, pix, color);
		}
	}
}
