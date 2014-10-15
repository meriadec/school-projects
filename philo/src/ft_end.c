/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 18:38:16 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 18:44:53 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "philo.h"

void					ft_end(t_env *env)
{
	char				buf[6];

	ft_bzero(buf, 6);
	ft_putstr("\n");
	ft_putstr("  Now, it is time... To DAAAAAAAANCE ! ! !\n");
	ft_putstr("          Press 'q' to quit\n");
	while (-1 != read(0, buf, 6))
	{
		if (!ft_strcmp(buf, "q"))
		{
			ft_reset_term();
			ft_liberate(env);
		}
		ft_bzero(buf, 6);
	}
}
