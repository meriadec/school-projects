/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 15:55:39 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/11 15:58:58 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <curses.h>
# include <term.h>
# include <time.h>
# include <pthread.h>
# include "libft.h"

# define MAX_LIFE		(20)
# define EAT_T			(2)
# define REST_T			(2)
# define THINK_T		(2)
# define TIMEOUT		(60)

# define NB_PHILO		(7)

# define OK				(0)
# define ERR			(-1)

# define TRYLOCK(X)		pthread_mutex_trylock(X)
# define UNLOCK(X)		pthread_mutex_unlock(X)

/*
** States
*/

enum	e_states { EATING, THINKING, RESTING };

/*
** Structures
*/

typedef struct			s_philo
{
	long				id;
	int					state;
	int					hp;
	pthread_t			thread;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	int					stick_l;
	int					stick_r;
}						t_philo;

typedef struct			s_env
{
	time_t				start;
	t_philo				philos[NB_PHILO];
	pthread_mutex_t		sticks[NB_PHILO];
	pthread_t			draw;
	int					death;
}						t_env;

/*
** Basics
*/

t_env					*ft_getenv(void);
void					ft_init(t_env *env);
void					*ft_philosopher(void *i);
void					ft_assign_sticks(t_philo *philo,
		pthread_mutex_t sticks[]);
void					ft_action_eat(t_env *env, t_philo *philo);
void					ft_action_think(t_env *env, t_philo *philo, char side);
void					ft_action_rest(t_env *env, t_philo *philo);
void					ft_timed_sleep(t_env *env, time_t seconds);
void					ft_liberate(t_env *env);

/*
** Errors
*/

void					ft_error(char *str);

/*
** Draw
*/

void					*ft_draw(void *param);

/*
** Termcaps
*/

void					ft_draw_philosopher(t_env *env, t_philo *philo);
int						ft_putput(int c);
void					ft_init_term(void);
int						ft_reset_term(void);
void					ft_raw_term(void);
void					ft_death(t_env *env);
void					ft_end(t_env *env);

#endif
