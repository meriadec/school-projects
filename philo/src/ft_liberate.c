/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liberate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 17:03:59 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 18:34:40 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

void					ft_liberate(t_env *env)
{
	int					i;

	i = 0;
	while (i < NB_PHILO)
	{
		if (0 != UNLOCK(&env->sticks[i]))
			ft_error("Cant unlock stick");
		if (0 != pthread_mutex_destroy(&env->sticks[i]))
			ft_error("Cant destroy mutex");
		if (0 != pthread_detach(env->philos[i].thread))
			ft_error("Cant detach philosopher thread");
		++i;
	}
	if (0 != pthread_detach(env->draw))
		ft_error("Cant detach draw thread");
	exit(0);
}
