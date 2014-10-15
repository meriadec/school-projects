/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shared_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:44:37 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 13:07:43 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <sys/stat.h>
#include <errno.h>
#include "draw.h"

int							ft_get_shared_mem(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	if (-1 == (ctx->segment_id = shmget(ctx->shm_key, ctx->page_size,
					S_IRUSR | S_IWUSR)))
		ft_error_exit("Can't find a valid shared memory");
	return (OK);
}
