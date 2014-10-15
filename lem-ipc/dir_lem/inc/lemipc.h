/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 12:39:59 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 17:22:13 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

/*
** ----------------------------------------------------------------------------
** Includes
** ----------------------------------------------------------------------------
*/

# include <sys/ipc.h>
# include "lem_shared.h"

/*
** ----------------------------------------------------------------------------
** Defines
** ----------------------------------------------------------------------------
*/

enum						e_sems { SEM_READ, SEM_WRITE, SEM_TMP };

# define POSX				ctx->pos.x
# define POSY				ctx->pos.y
# define HERE				MAP[POSY][POSX]

# define USEMUN				union semun
# define SEMBUF				struct sembuf

/*
** ----------------------------------------------------------------------------
** Structures
** ----------------------------------------------------------------------------
*/

typedef struct				s_pos
{
	int						x;
	int						y;
}							t_pos;

typedef struct				s_ctx
{
	char					*prog_name;
	int						team;
	int						segment_id;
	key_t					shm_key;
	int						page_size;
	t_shared				*shared;
	t_pos					pos;
	int						semid;
}							t_ctx;

/*
** ----------------------------------------------------------------------------
** Prototypes
** ----------------------------------------------------------------------------
*/

/*
** Context
*/

t_ctx						*ft_ctx(void);
void						ft_set_params(char *team, char *prog_name);

/*
** Core
*/

int							ft_get_shared_mem(void);
int							ft_create_shared_mem(void);
key_t						ft_get_key(void);
void						ft_open_shared(void);
void						ft_close_shared(void);
void						ft_place(void);
void						ft_liberate(void);
void						ft_create_semaphores(void);
int							ft_is_dead(void);
void						ft_play(void);

/*
** Semaphores
*/

void						sem_read_start(void);
void						sem_read_end(void);
void						sem_write_start(void);
void						sem_write_end(void);

/*
** Moves
*/

void						ft_move_left(void);
void						ft_move_right(void);
void						ft_move_up(void);
void						ft_move_down(void);

/*
** Errors
*/

int							ft_error(char *str);
void						ft_error_exit(char *str);
void						ft_exit(void);
int							ft_usage(char *name);

/*
** Utils
*/

void						ft_wait_q(void);
void						ft_print_map(void);

#endif
