/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 13:54:22 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 14:39:42 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int							ft_pwd(t_ctx *ctx)
{
	char					*tmp;

	tmp = ft_strjoin(ctx->pwd, "\n");
	ft_send(tmp, STR_SUCCESS);
	ft_memdel((void **)&tmp);
	return (OK);
}
