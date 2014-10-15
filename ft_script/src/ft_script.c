/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 18:31:04 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 18:34:00 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include "ft_script.h"

static void				st_head(t_opt *opts)
{
	write(1, "Script started, output file is ", 31);
	ft_putendl(opts->file);
	write(opts->fd, "Script started on ", 18);
	ft_date(opts->fd);
}

static int				st_child(t_opt *opts)
{
	if (!opts->q)
		st_head(opts);
	close(opts->master);
	close(opts->fd);
	if (ERR == ft_shell(opts))
		return (ERR);
	return (OK);
}

int						ft_script(t_opt *opts)
{
	int					pid;

	if (ERR == ft_open_file(opts))
		return (ERR);
	if (ERR == ft_get_master_and_slave(opts))
	{
		ft_putendl_fd("Problem.", 2);
		return (ERR);
	}
	ft_signal(SIGCHLD, ft_sig_child);
	ft_raw(opts);
	pid = fork();
	if (pid == 0)
		st_child(opts);
	else
	{
		close(opts->slave);
		ft_io(opts, pid);
	}
	return (OK);
}
