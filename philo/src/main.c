/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:55:26 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 15:33:53 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "philo.h"

static void				st_sig_stp(int sig)
{
	(void)sig;
	ft_reset_term();
	exit(OK);
}

int						main(void)
{
	t_env				*env;

	ft_init_term();
	ft_raw_term();
	if (SIG_ERR == signal(SIGINT, st_sig_stp))
		ft_error("Signal failed.");
	env = ft_getenv();
	env->start = time(NULL);
	ft_init(env);
	ft_reset_term();
	ft_putendl("Now, it is time... To DAAAAAAAANCE ! ! !");
	return (0);
}
