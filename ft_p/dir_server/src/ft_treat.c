/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 17:39:12 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 14:57:48 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int							ft_treat(char *cmd)
{
	t_ctx					*ctx;

	ctx = ft_ctx();
	if (!ft_strcmp(cmd, "ls"))
		return (ft_ls(ctx));
	else if (!ft_strcmp(cmd, "pwd"))
		return (ft_pwd(ctx));
	else if (ft_startswith(cmd, "cd"))
		return (ft_cd(ctx, cmd));
	return (OK);
}
