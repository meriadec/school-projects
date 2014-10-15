/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_master_and_slave.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 19:55:33 by mpillet           #+#    #+#             */
/*   Updated: 2014/04/30 20:08:44 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include "ft_script.h"

int						ft_get_master_and_slave(t_opt *opts)
{
	static char			ptsname[128];
	struct stat			sbuf;
	char				*ret;
	int					pty;
	int					tty;

	if (-1 == (pty = open("/dev/ptmx", O_RDWR)))
		return (ERR);
	if (-1 == ioctl(pty, TIOCPTYGRANT))
		return (ERR);
	if (-1 == ioctl(pty, TIOCPTYUNLK))
		return (ERR);
	ret = NULL;
	if (-1 == ioctl(pty, TIOCPTYGNAME, ptsname))
		return (ERR);
	if (-1 == stat(ptsname, &sbuf))
		return (ERR);
	ret = ptsname;
	if (-1 == (tty = open(ret, O_RDWR)))
		return (ERR);
	opts->master = pty;
	opts->slave = tty;
	return (OK);
}
