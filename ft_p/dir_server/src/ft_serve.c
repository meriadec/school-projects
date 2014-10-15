/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:05:59 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/16 18:43:44 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "server.h"

static int					st_read(int cs)
{
	char					buf[BUF_LEN];
	int						r;

	while ((r = read(cs, buf, BUF_LEN - 1)) > 0)
	{
		buf[r] = '\0';
		ft_treat(buf);
		ft_bzero(buf, BUF_LEN);
	}
	if (-1 == close(cs))
		return (ft_error("Cant close client socket"));
	return (OK);
}

int							ft_serve(void)
{
	t_ctx					*ctx;
	int						cs;
	unsigned int			cslen;
	struct sockaddr_in		csin;
	int						father;

	ctx = ft_ctx();
	if (-1 == (cs = accept(ctx->sock, (struct sockaddr *)&csin, &cslen)))
		return (ft_error("Cant accept connexions"));
	ctx->cs = cs;
	ft_success("Client connected !");
	father = fork();
	if (!father)
	{
		if (ERR == st_read(cs))
			return (ERR);
	}
	else
		ft_serve();
	return (OK);
}
