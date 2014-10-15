/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 12:05:18 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/11 15:03:49 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "philo.h"

static int				check_around(t_env *env, t_philo *philo)
{
	if (env->philos[philo->id - 1 % NB_PHILO].hp < philo->hp
		|| env->philos[philo->id + 1 % NB_PHILO].hp < philo->hp)
	{
		return (0);
	}
	return (1);
}

static void				st_decision(t_env *env, t_philo *philo)
{
	int					left;
	int					right;

	if (check_around(env, philo))
	{
		left = TRYLOCK(philo->left);
		right = TRYLOCK(philo->right);
		if (0 == left && 0 == right)
			ft_action_eat(env, philo);
		else if (0 == left)
			ft_action_think(env, philo, 'L');
		else if (0 == right)
			ft_action_think(env, philo, 'R');
		else
			ft_action_rest(env, philo);
	}
	else
		ft_action_rest(env, philo);
}

void					*ft_philosopher(void *i)
{
	t_env				*env;
	t_philo				*philo;
	time_t				now;

	env = ft_getenv();
	philo = &(env->philos[(long)i]);
	philo->id = (long)i;
	ft_assign_sticks(philo, env->sticks);
	now = time(NULL);
	while (philo->hp > 0 && now - env->start < TIMEOUT && !env->death)
	{
		st_decision(env, philo);
		now = time(NULL);
	}
	return (NULL);
}
