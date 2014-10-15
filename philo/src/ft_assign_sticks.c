/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_sticks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 17:40:31 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/08 17:45:42 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void					ft_assign_sticks(t_philo *philo,
		pthread_mutex_t sticks[])
{
	philo->left = &sticks[philo->id];
	philo->right = &sticks[(philo->id + 1) % NB_PHILO];
}
