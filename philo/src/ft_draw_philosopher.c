/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_philosopher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 15:27:53 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 17:02:02 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void				st_life(t_philo *philo)
{
	int					i;

	i = 0;
	if (philo->hp < MAX_LIFE / 3)
		ft_putstr("\033[7;31m");
	else
		ft_putstr("\033[7;32m");
	while (i < philo->hp)
	{
		ft_putchar(' ');
		ft_putstr("\033[0m");
		ft_putchar(' ');
		if (philo->hp < MAX_LIFE / 3)
			ft_putstr("\033[7;31m");
		else
			ft_putstr("\033[7;32m");
		++i;
	}
	ft_putstr("\033[0m");
}

static void				st_sticks(t_philo *philo)
{
	ft_putstr("\033[0;35m");
	if (philo->stick_l && philo->stick_r)
		ft_putstr("L R ");
	else if (philo->stick_l)
		ft_putstr("L   ");
	else if (philo->stick_r)
		ft_putstr("R   ");
	else
		ft_putstr("    ");
	ft_putstr("\033[0m");
	ft_putchar(' ');
}

static void				st_state(t_philo *philo)
{
	if (philo->state == EATING)
		ft_putstr("\033[1;37mEATING   ");
	else if (philo->state == THINKING)
		ft_putstr("THINKING ");
	else if (philo->state == RESTING)
		ft_putstr("RESTING  ");
	ft_putstr("\033[0m");
}

static void				st_dead(void)
{
	ft_putstr("\033[7;31m");
	ft_putstr(" DEAD ");
	ft_putstr("\033[0m\n\n");
}

void					ft_draw_philosopher(t_env *env, t_philo *philo)
{
	(void)env;
	ft_putstr(" \033[7;36m ");
	ft_putnbr((int)philo->id + 1);
	ft_putstr(" \033[0m ");
	if (philo->hp <= 0)
		st_dead();
	else
	{
		st_state(philo);
		st_sticks(philo);
		st_life(philo);
		ft_putstr("\n\n");
	}
}
