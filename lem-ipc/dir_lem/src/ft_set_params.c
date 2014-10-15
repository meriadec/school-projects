/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:39:08 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 13:11:11 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lemipc.h"

void						ft_set_params(char *prog_name, char *team)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	ctx->prog_name = prog_name;
	ctx->team = ft_atoi(team);
	if (0 == ctx->team)
		ft_error_exit("Team cannot be 0");
	ctx->shm_key = ft_get_key();
	ctx->page_size = getpagesize();
}
