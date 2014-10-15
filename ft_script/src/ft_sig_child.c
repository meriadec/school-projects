/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 16:14:05 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 16:29:26 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_script.h"

void					ft_sig_child(int sig)
{
	t_opt				*opts;

	(void)sig;
	opts = ft_get_opts();
	if (!opts->q)
		write(1, "\n", 1);
	if (opts->zombi)
		ft_end(opts->zombi);
	else
		ft_end(0);
}
