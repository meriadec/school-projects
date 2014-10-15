/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:27:23 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/14 16:49:50 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "server.h"

int							ft_close_server(void)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	if (-1 == close(ctx->sock))
		return (ERR);
	return (ft_success("Client disconnected"));
}
