/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 11:39:05 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 19:10:39 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/shm.h>
#include "lemipc.h"

static void					st_bye_bye(t_ctx *ctx)
{
	--ctx->shared->nb;
	HERE = 0;
	if (!ctx->shared->nb)
		ft_liberate();
	ft_putendl("\nBye !\n");
}

static void					st_sig_stp(int sig)
{
	t_ctx					*ctx;

	(void)sig;
	ctx = ft_ctx();
	st_bye_bye(ctx);
	ft_exit();
}

int							main(int ac, char **av)
{
	t_ctx					*ctx;

	if (ac != 2)
		return (ft_usage(av[0]));
	ft_set_params(av[0], av[1]);
	if (ERR == ft_get_shared_mem())
		ft_error_exit("Can't get shared memory");
	if (SIG_ERR == signal(SIGINT, st_sig_stp))
		ft_error_exit("Signal failed.");
	ctx = ft_ctx();
	ft_open_shared();
	++ctx->shared->nb;
	ft_place();
	ft_play();
	st_bye_bye(ctx);
	return (OK);
}
