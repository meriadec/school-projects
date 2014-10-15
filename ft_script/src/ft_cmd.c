/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:47:26 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 19:56:31 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_script.h"

int						ft_cmd(t_opt *opts)
{
	char				cmd[4096];

	ft_bzero(cmd, 4096);
	if (ERR == ft_find_path(opts, cmd))
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(opts->cmd[0], 2);
		return (ERR);
	}
	opts->cmd[0] = cmd;
	execve(opts->cmd[0], opts->cmd, opts->env);
	return (OK);
}
