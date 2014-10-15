/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 12:48:31 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 16:46:57 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <sys/shm.h>
#include "draw.h"

int						main(void)
{
	t_ctx				*ctx;

	ctx = ft_ctx();
	ctx->shm_key = ft_get_key();
	if (ERR == ft_get_shared_mem())
		ft_error_exit("Can't get shared memory");
	ctx->w.mlx = mlx_init();
	ctx->w.img = NULL;
	ctx->w.win = mlx_new_window(ctx->w.mlx, WIDTH, HEIGHT, "IPC");
	ctx->shared = (t_shared *)shmat(ctx->segment_id, 0, 0);
	ctx->w.img = mlx_new_image(MLX, WIDTH, HEIGHT);
	mlx_key_hook(ctx->w.win, key_hook, ctx);
	mlx_loop_hook(ctx->w.mlx, ft_loop, ctx);
	mlx_loop(ctx->w.mlx);
	shmdt(ctx->shared);
	return (OK);
}
