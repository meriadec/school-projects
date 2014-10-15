/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_shared_mem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 15:09:11 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 17:43:42 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include "lemipc.h"

static void					st_create_map(void)
{
	t_ctx					*ctx;
	int						x;
	int						y;

	ctx = ft_ctx();
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			MAP[y][x] = 0;
			++x;
		}
		++y;
	}
}

int							ft_create_shared_mem(void)
{
	t_ctx					*ctx;

	ft_putstr("creating shared memory...");
	ctx = ft_ctx();
	if (-1 == (ctx->segment_id = shmget(ctx->shm_key, ctx->page_size * 8,
					IPC_CREAT | S_IRUSR | S_IWUSR)))
		return (ERR);
	ft_putendl("\033[0;32m[DONE]\033[0m");
	ft_create_semaphores();
	ft_open_shared();
	ctx->shared->nb = 0;
	ctx->shared->first = ctx->team;
	st_create_map();
	ft_close_shared();
	return (OK);
}
