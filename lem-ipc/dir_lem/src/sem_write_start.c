/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_write_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 12:05:31 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:12:44 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include "lemipc.h"

void						sem_write_start(void)
{
	t_ctx					*ctx;
	SEMBUF					sembuf[3];

	ctx = ft_ctx();
	sembuf[0].sem_num = SEM_READ;
	sembuf[0].sem_op = 0;
	sembuf[0].sem_flg = SEM_UNDO;
	sembuf[1].sem_num = SEM_WRITE;
	sembuf[1].sem_op = -1;
	sembuf[1].sem_flg = SEM_UNDO;
	sembuf[2].sem_num = SEM_TMP;
	sembuf[2].sem_op = 1;
	sembuf[2].sem_flg = SEM_UNDO;
	if (-1 == semop(ctx->semid, sembuf, 3))
		ft_error_exit("Can't semop");
}
