/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_read_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 12:05:27 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:12:36 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include "lemipc.h"

void						sem_read_start(void)
{
	t_ctx					*ctx;
	SEMBUF					sembuf[2];

	ctx = ft_ctx();
	sembuf[0].sem_num = SEM_TMP;
	sembuf[0].sem_op = 0;
	sembuf[0].sem_flg = SEM_UNDO;
	sembuf[1].sem_num = SEM_READ;
	sembuf[1].sem_op = 1;
	sembuf[1].sem_flg = SEM_UNDO;
	if (-1 == semop(ctx->semid, sembuf, 2))
		ft_error_exit("Can't semop");
}
