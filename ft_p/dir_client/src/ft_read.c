/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 17:33:07 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 16:13:21 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "client.h"

static void					st_replace_pwd(t_ctx *ctx, char *ret)
{
	char					**tmp;

	tmp = ft_strsplit(ret, '\n');
	if (ft_strstr(tmp[1], "SUCCESS"))
	{
		ft_putendl(tmp[1]);
		ft_memdel((void **)&ctx->pwd);
		ctx->pwd = ft_strdup(tmp[0]);
	}
	else
		ft_putendl(ret);
	ft_free_tab((void ***)&tmp);
}

static int					st_talk(t_ctx *ctx, char *buf, char *ret, int cd)
{
	if (-1 == send(ctx->sock, buf, ft_strlen(buf), 0))
		return (ft_error("Problem sending data"));
	ft_bzero(ret, BUF_LEN);
	if (-1 == recv(ctx->sock, ret, BUF_LEN, 0))
		return (ft_error("Server not responding"));
	if (cd)
		st_replace_pwd(ctx, ret);
	else
		ft_putendl(ret);
	return (OK);
}

int							ft_read(void)
{
	t_ctx					*ctx;
	char					*buf;
	char					ret[BUF_LEN];

	ctx = ft_ctx();
	buf = NULL;
	ft_prompt();
	while (get_next_line(0, &buf))
	{
		ft_bzero(ret, BUF_LEN);
		if (ft_is_valid(&buf))
		{
			if (0 == ft_strcmp(buf, "quit"))
				return (ft_success("See you soon"));
			if (ERR == st_talk(ctx, buf, ret, ft_is_cd(buf)))
				return (ERR);
		}
		ft_prompt();
		ft_memdel((void **)&buf);
	}
	return (OK);
}
