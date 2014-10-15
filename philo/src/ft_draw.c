/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:40:25 by hmassing          #+#    #+#             */
/*   Updated: 2014/05/10 18:38:01 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

static void				st_remove_life(t_env *env)
{
	int					i;

	i = 0;
	while (i < NB_PHILO)
	{
		if (env->philos[i].state != EATING)
			--env->philos[i].hp;
		if (env->philos[i].hp <= 0)
			env->death = 1;
		++i;
	}
}

static void				st_draw_loop(t_env *env)
{
	int					i;

	tputs(tgetstr("cl", NULL), 1, ft_putput);
	ft_putchar('\n');
	i = 0;
	while (i < NB_PHILO)
	{
		ft_draw_philosopher(env, &env->philos[i]);
		++i;
	}
}

void					*ft_draw(void *param)
{
	t_env				*env;
	time_t				now;

	env = ft_getenv();
	(void)param;
	now = time(NULL);
	while (1 && now - env->start < TIMEOUT)
	{
		st_remove_life(env);
		st_draw_loop(env);
		if (env->death)
		{
			ft_death(env);
			return (NULL);
		}
		usleep(1 * 1000000);
		now = time(NULL);
	}
	ft_end(env);
	return (NULL);
}
