/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 14:50:44 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 14:51:43 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include <mlx.h>
#include <stdlib.h>
#include "draw.h"

int							key_hook(int keycode, t_ctx *ctx)
{
	if (keycode == 65307)
	{
		shmdt(ctx->shared);
		exit(0);
	}
	return (0);
}
