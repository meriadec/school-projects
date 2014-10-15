/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_semaphores.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 19:03:09 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 17:21:14 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <sys/types.h>
#include "lemipc.h"

void						ft_create_semaphores(void)
{
	t_ctx					*ctx;
	USEMUN					semun;
	u_short					sems[3];

	ft_putstr("creating semaphores...");
	ctx = ft_ctx();
	if (-1 == (ctx->semid = semget(ctx->shm_key, 3, 0666 | IPC_CREAT)))
		ft_error_exit("Can't semget");
	sems[SEM_READ] = 0;
	sems[SEM_WRITE] = 1;
	sems[SEM_TMP] = 0;
	semun.array = sems;
	if (-1 == semctl(ctx->semid, 1, SETALL, semun))
		ft_error_exit("Can't semctl");
	ft_putendl("\033[0;32m[DONE]\033[0m");
}
