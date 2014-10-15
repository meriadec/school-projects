/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:53:09 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:18:11 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lemipc.h"

void						ft_move_down(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	if (ctx->pos.y < H - 1 && !MAP[POSY + 1][POSX])
	{
		sem_write_start();
		HERE = 0;
		++(POSY);
		HERE = ctx->team;
		sem_write_end();
		usleep(100000);
	}
}
