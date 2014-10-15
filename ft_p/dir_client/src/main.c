/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:19:09 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 15:38:09 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "client.h"

int					main(int ac, char **av)
{
	t_ctx			*ctx;

	if (ac != 3)
		return (ft_usage(av[0]));
	ctx = ft_ctx();
	ctx->addr = av[1];
	ctx->pwd = ft_strdup("/");
	ctx->port = ft_atoi(av[2]);
	if (ERR == ft_create_client())
		return (ERR);
	ft_success("Connexion etablished !");
	if (ERR == ft_read())
		ft_error("Error reading things");
	close(ctx->sock);
	return (OK);
}
