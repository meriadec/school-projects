/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:19:09 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 14:57:49 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "server.h"

static int			st_set_defaults(t_ctx *ctx, char **env, char *port)
{
	ctx->env = ft_dup_env(env);
	ctx->port = ft_atoi(port);
	if (NULL == (ctx->root = getcwd(NULL, 0)))
		return (ft_error("Cant getcwd"));
	ctx->pwd = ft_strdup("/");
	ctx->old_pwd = NULL;
	return (OK);
}

int					main(int ac, char **av, char **env)
{
	t_ctx			*ctx;

	if (ac != 2)
		return (ft_usage(av[0]));
	ctx = ft_ctx();
	if (ERR == st_set_defaults(ctx, env, av[1]))
		return (ERR);
	if (ERR == ft_create_server())
		return (ft_error("Cant create server"));
	ft_success("Server started !");
	if (ERR == ft_serve())
		return (ft_error("Cant serve anything"));
	if (ERR == ft_close_server())
		return (ft_error("Cant close server"));
	return (ft_clear());
}
