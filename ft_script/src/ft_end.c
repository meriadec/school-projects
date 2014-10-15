/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 16:16:50 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 18:13:07 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_script.h"

void					ft_end(int pid)
{
	t_opt				*opts;

	opts = ft_get_opts();
	if (pid)
		kill(pid, SIGUSR1);
	if (!opts->q)
	{
		write(1, "Script done, output file is ", 28);
		ft_putendl(opts->file);
		write(opts->fd, "\nScript done on ", 16);
		ft_date(opts->fd);
	}
	close(opts->fd);
	ft_reset_term(opts);
	_exit(0);
}
