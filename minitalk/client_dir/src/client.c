/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 13:22:13 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/09 19:50:54 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

static int		st_is_ok(int assign)
{
	static int		is_ok = 0;

	if (assign != -1)
		is_ok = assign;
	return (is_ok);
}

static void		sig_handler(int sig)
{
	(void) sig;
	if (SIGUSR1 == sig)
		st_is_ok(1);
	else
	{
		ft_putstr_fd("\033[0;31m", 2);
		ft_putendl_fd("Server fucked up, bye.", 2);
		ft_putstr_fd("\033[0m", 2);
		exit(42);
	}
}

static void		ft_wait_response(int *timeout)
{
	usleep(10);
	++(*timeout);
	if ((*timeout) > 10000)
		ft_err_timeout();
}

static void		ft_send(int server, char *msg)
{
	int			i;
	int			bit;
	int			timeout;

	while (*msg)
	{
		i = 0;
		while (i < 8)
		{
			st_is_ok(0);
			timeout = 0;
			bit = (*msg >> i) & 1;
			if (0 == bit)
				kill(server, SIGUSR2);
			else
				kill(server, SIGUSR1);
			while (!st_is_ok(-1))
				ft_wait_response(&timeout);
			++i;
		}
		++msg;
	}
}

int				main(int ac, char **av)
{
	int			server;

	if (ac == 3)
	{
		if (SIG_ERR == signal(SIGUSR1, sig_handler)
				|| SIG_ERR == signal(SIGUSR2, sig_handler))
		{
			ft_putendl_fd("Cant set signal.", 2);
			exit(1);
		}
		server = ft_atoi(av[1]);
		ft_send(server, av[2]);
		ft_send(server, "\004");
	}
	else
		ft_putendl_fd("usage: ./client <server_id> <msg>", 2);
	return (0);
}
