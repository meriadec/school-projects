/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:49:21 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:17:48 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lemipc.h"

void						ft_move_right(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	if (ctx->pos.x < W - 1 && !MAP[POSY][POSX + 1])
	{
		sem_write_start();
		HERE = 0;
		++(POSX);
		HERE = ctx->team;
		sem_write_end();
		usleep(100000);
	}
}
