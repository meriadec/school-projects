/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 19:26:09 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:28:48 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

static void					st_find_target(t_ctx *ctx, int map[H][W],
		int target[2])
{
	int						x;
	int						y;

	target[0] = POSX;
	target[1] = POSY;
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			if (map[y][x] && map[y][x] != ctx->team)
			{
				target[0] = x;
				target[1] = y;
				break ;
			}
			++x;
		}
		++y;
	}
}

static void					st_find_and_move(t_ctx *ctx)
{
	int						map[H][W];
	int						target[2];

	sem_read_start();
	st_find_target(ctx, MAP, target);
	sem_read_end();
	(void)map;
	if (target[0] == POSX && target[1] == POSY)
		return ;
	if (target[0] < POSX)
		ft_move_left();
	if (target[0] > POSX)
		ft_move_right();
	if (target[1] < POSY)
		ft_move_up();
	if (target[1] > POSY)
		ft_move_down();
}

static int					st_win(t_ctx *ctx)
{
	int						x;
	int						y;

	sem_read_start();
	if (!ctx->shared->first)
	{
		y = -1;
		while (++y < H)
		{
			x = -1;
			while (++x < W)
			{
				if (MAP[y][x] && MAP[y][x] != ctx->team)
				{
					sem_read_end();
					return (0);
				}
			}
		}
		sem_read_end();
		ft_putendl("YOUR TEAM WON !");
		return (1);
	}
	return (0);
}

void						ft_play(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	(void)st_win;
	while (!ft_is_dead())
		st_find_and_move(ctx);
}
