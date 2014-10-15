/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liberate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 18:05:05 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 11:29:48 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <sys/shm.h>
#include "lemipc.h"

void						ft_liberate(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	ft_close_shared();
	ft_putstr("\nliberating shared memory...");
	if (-1 == shmctl(ctx->segment_id, IPC_RMID, 0))
		ft_error_exit("Can't smctl");
	ft_putendl("\033[0;32m[DONE]\033[0m");
	ft_putstr("liberating semaphores...");
	if (-1 == semctl(ctx->semid, 1, IPC_RMID))
		ft_error_exit("Can't liberate semaphores");
	ft_putendl("\033[0;32m[DONE]\033[0m");
}
