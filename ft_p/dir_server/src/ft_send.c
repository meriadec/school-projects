/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:44:59 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 16:21:04 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "server.h"

int							ft_send(char *str, char *ret)
{
	t_ctx					*ctx;
	char					*tmp;
	char					*tmp2;
	char					*tmp3;
	char					*tmp4;

	ctx = ft_ctx();
	tmp2 = ft_strjoin("\n", ret);
	tmp4 = ft_strjoin(tmp2, "\n");
	tmp = ft_strjoin(str, tmp4);
	tmp3 = ft_strjoin("\n", tmp);
	send(ctx->cs, tmp3, ft_strlen(tmp3), 0);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&tmp2);
	ft_memdel((void **)&tmp3);
	ft_memdel((void **)&tmp4);
	return (OK);
}
