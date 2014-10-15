/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 12:15:12 by hmassing          #+#    #+#             */
/*   Updated: 2014/05/11 15:10:02 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void					ft_action_think(t_env *env, t_philo *philo, char side)
{
	philo->state = THINKING;
	if (side == 'L')
	{
		philo->stick_l = 1;
		philo->stick_r = 0;
	}
	else if (side == 'R')
	{
		philo->stick_l = 0;
		philo->stick_r = 1;
	}
	ft_timed_sleep(env, THINK_T);
	if (side == 'L')
		UNLOCK(philo->left);
	else
		UNLOCK(philo->right);
}
