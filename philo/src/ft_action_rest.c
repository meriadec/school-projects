/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 12:29:49 by hmassing          #+#    #+#             */
/*   Updated: 2014/05/10 16:24:58 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void					ft_action_rest(t_env *env, t_philo *philo)
{
	(void)env;
	philo->state = RESTING;
	philo->stick_l = 0;
	philo->stick_r = 0;
	ft_timed_sleep(env, REST_T);
}
