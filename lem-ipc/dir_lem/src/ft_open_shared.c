/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_shared.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:42:42 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 16:43:31 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include "lemipc.h"

void						ft_open_shared(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	ctx->shared = (t_shared *)shmat(ctx->segment_id, 0, 0);
}
