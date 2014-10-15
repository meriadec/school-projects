/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shared_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:44:37 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 17:45:52 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <errno.h>
#include "lemipc.h"

int							ft_get_shared_mem(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	if (-1 == (ctx->segment_id = shmget(ctx->shm_key, ctx->page_size,
					S_IRUSR | S_IWUSR)))
	{
		if (ENOENT == errno)
			return (ft_create_shared_mem());
		else
			return (ERR);
	}
	if (-1 == (ctx->semid = semget(ctx->shm_key, 3, 0666)))
		ft_error_exit("Can't semget");
	ft_open_shared();
	if (ctx->shared->first && ctx->shared->first != ctx->team)
		ctx->shared->first = 0;
	ft_close_shared();
	return (OK);
}
