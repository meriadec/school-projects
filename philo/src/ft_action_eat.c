/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 18:46:26 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 16:24:15 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void					ft_action_eat(t_env *env, t_philo *philo)
{
	(void)env;
	philo->state = EATING;
	philo->stick_l = 1;
	philo->stick_r = 1;
	ft_timed_sleep(env, EAT_T);
	UNLOCK(philo->left);
	UNLOCK(philo->right);
	philo->hp = MAX_LIFE;
}
