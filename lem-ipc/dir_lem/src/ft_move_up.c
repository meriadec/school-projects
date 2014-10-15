/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:50:25 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:24:53 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lemipc.h"

void						ft_move_up(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	if (ctx->pos.y > 0 && !MAP[POSY - 1][POSX])
	{
		sem_write_start();
		HERE = 0;
		--(POSY);
		HERE = ctx->team;
		sem_write_end();
		usleep(100000);
	}
}
