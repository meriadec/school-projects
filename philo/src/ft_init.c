/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 12:03:45 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 18:31:41 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

static void				st_create_mutex(t_env *env)
{
	int					i;

	i = 0;
	while (i < NB_PHILO)
	{
		if (0 != pthread_mutex_init(&env->sticks[i], NULL))
			ft_error("Problem creating mutex.");
		++i;
	}
}

static void				st_set_defaults(t_env *env)
{
	int					i;

	i = 0;
	while (i < NB_PHILO)
	{
		env->philos[i].hp = MAX_LIFE;
		env->philos[i].state = RESTING;
		env->philos[i].stick_l = 0;
		env->philos[i].stick_r = 0;
		++i;
	}
}

static void				st_create_philosophers(t_env *env)
{
	long				i;

	i = 0;
	st_set_defaults(env);
	while (i < NB_PHILO)
	{
		if (0 != pthread_create(&(env->philos[i].thread), NULL, ft_philosopher,
					(void *)i))
			ft_error("Problem creating thread.");
		++i;
	}
	if (0 != pthread_join(env->draw, NULL))
		ft_error("Problem joining draw");
	i = 0;
	while (i < NB_PHILO)
	{
		if (0 != pthread_join(env->philos[i].thread, NULL))
			ft_error("Problem joining threads.");
		++i;
	}
}

void					ft_init(t_env *env)
{
	if (0 != pthread_create(&env->draw, NULL, ft_draw, NULL))
		ft_error("Draw can not be initialized");
	st_create_mutex(env);
	st_create_philosophers(env);
}
