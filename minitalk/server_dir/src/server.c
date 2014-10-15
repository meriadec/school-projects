/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 13:46:55 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/09 17:41:45 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "minitalk.h"

void			sig_handler(int sig, siginfo_t *info, void *uap)
{
	static int			last_pid = 0;

	if (info->si_pid)
		last_pid = info->si_pid;
	(void) uap;
	if (SIGUSR1 == sig)
		ft_read_input(1);
	else
		ft_read_input(0);
	if (info->si_pid > 0)
		kill(info->si_pid, SIGUSR1);
	else
	{
		kill(last_pid, SIGUSR2);
		ft_putstr_fd("\033[0;31m", 2);
		ft_putendl_fd("I fucked up.", 2);
		ft_putstr_fd("\033[0m", 2);
		exit(42);
	}
}

void			ft_set_signals(void)
{
	struct sigaction		act;
	struct sigaction		oact;

	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	if (-1 == sigaction(SIGUSR1, &act, &oact)
			|| -1 == sigaction(SIGUSR2, &act, &oact))
	{
		ft_putendl_fd("Can't set signals", 2);
		exit(1);
	}
}

int				main(void)
{
	ft_aff_pid();
	ft_set_signals();
	while (1)
		pause();
	return (0);
}
