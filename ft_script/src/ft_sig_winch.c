/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_winch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 17:45:41 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 17:48:38 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_script.h"

void					ft_sig_winch(int sig)
{
	t_opt				*opts;
	struct winsize		ws;

	(void)sig;
	opts = ft_get_opts();
	signal(SIGWINCH, ft_sig_winch);
	if (ioctl(0, TIOCGWINSZ, &ws) != -1)
		ioctl(opts->master, TIOCSWINSZ, &ws);
}
