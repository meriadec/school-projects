/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_usr1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 17:00:52 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 17:20:21 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_script.h"

void					ft_sig_usr1(int sig)
{
	t_opt				*opts;

	(void)sig;
	opts = ft_get_opts();
	close(opts->fd);
	ft_reset_term(opts);
	_exit(-1);
}
