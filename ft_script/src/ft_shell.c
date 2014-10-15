/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 18:55:25 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 18:46:56 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include "ft_script.h"

static int				st_login(int fd)
{
	int					out;

	setsid();
	out = ioctl(fd, TIOCSCTTY, NULL);
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	close(fd);
	return (out);
}

int						ft_shell(t_opt *opts)
{
	char				*arr[3];

	if (-1 == st_login(opts->slave))
	{
		ft_putendl_fd("Problem.", 2);
		_exit(-1);
	}
	if (opts->cmd)
		return (ft_cmd(opts));
	arr[0] = opts->shell;
	arr[1] = "-i";
	arr[2] = NULL;
	if (-1 == execve(opts->shell, arr, opts->env))
	{
		ft_putendl_fd("Can't exec shell", 2);
		return (ERR);
	}
	return (OK);
}
