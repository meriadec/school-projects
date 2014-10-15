/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_server.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:09:56 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/13 17:18:39 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "server.h"

int							ft_create_server(void)
{
	t_ctx					*ctx;
	struct protoent			*proto;
	struct sockaddr_in		sin;

	ctx = ft_ctx();
	if (NULL == (proto = getprotobyname("tcp")))
		return (ft_error("Failed executing 'getprotobyname'"));
	if (-1 == (ctx->sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)))
		return (ft_error("Failed executing 'socket'"));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(ctx->port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (-1 == bind(ctx->sock, (const struct sockaddr *)&sin, sizeof(sin)))
		return (ft_error("Failed executing 'bind'"));
	if (-1 == listen(ctx->sock, 42))
		return (ft_error("Failed executing 'listen'"));
	return (OK);
}
