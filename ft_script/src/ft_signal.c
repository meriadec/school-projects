/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 16:08:58 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 16:28:42 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_script.h"

sig_t					ft_signal(int s, void (*func)(int))
{
	struct sigaction	sa;
	struct sigaction	osa;
	sigset_t			sigintr;

	sigintr = 0;
	sa.sa_handler = func;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (!sigismember(&sigintr, s))
		sa.sa_flags |= SA_RESTART;
	if (sigaction(s, &sa, &osa) < 0)
		return (SIG_ERR);
	return (osa.sa_handler);
}
