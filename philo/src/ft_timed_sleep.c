/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timed_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 12:57:08 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 13:24:56 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include "philo.h"

void					ft_timed_sleep(t_env *env, time_t seconds)
{
	time_t				now;
	time_t				rest;

	now = time(NULL);
	rest = TIMEOUT - (now - env->start);
	if (seconds > rest)
		usleep(rest * 1000000);
	else
		usleep(seconds * 1000000);
}
