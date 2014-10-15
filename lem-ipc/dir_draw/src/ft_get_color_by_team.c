/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_by_team.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 15:46:13 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 16:15:02 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_rgb				st_get_color(int r, int g, int b)
{
	t_rgb					color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_rgb						ft_get_color_by_team(int team)
{
	if (0 == team)
		return (st_get_color(30, 30, 30));
	else if (1 == team)
		return (st_get_color(120, 0, 0));
	else if (2 == team)
		return (st_get_color(0, 120, 0));
	else if (3 == team)
		return (st_get_color(0, 0, 120));
	else if (4 == team)
		return (st_get_color(120, 0, 120));
	else if (5 == team)
		return (st_get_color(0, 120, 120));
	else if (6 == team)
		return (st_get_color(120, 120, 0));
	else if (7 == team)
		return (st_get_color(20, 120, 200));
	else if (8 == team)
		return (st_get_color(120, 20, 200));
	else if (9 == team)
		return (st_get_color(120, 200, 20));
	else
		return (st_get_color(255, 255, 255));
}
