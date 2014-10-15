/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_read_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 12:05:29 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:12:32 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include "lemipc.h"

void						sem_read_end(void)
{
	t_ctx					*ctx;
	SEMBUF					sembuf[1];

	ctx = ft_ctx();
	sembuf[0].sem_num = SEM_READ;
	sembuf[0].sem_op = -1;
	sembuf[0].sem_flg = SEM_UNDO;
	if (-1 == semop(ctx->semid, sembuf, 1))
		ft_error_exit("Can't semop");
}
