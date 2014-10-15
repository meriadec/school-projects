/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:36:04 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 18:40:00 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Includes
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

# include <curses.h>
# include <term.h>
# include "libft.h"

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Defines
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

# define FALSE			0
# define TRUE			1

# define BUF_LEN		6

# define COLS_MIN		7
# define ROWS_MIN		6
# define NB_PIECES		42

# define CTX			(ft_get_ctx())
# define G(X, Y)		(grid[Y][X])

# define TYPE_ROOT		0
# define TYPE_IA		1
# define TYPE_OPP		2
# define TYPE_LEAF		3

# define NB_KEYS		2
# define K_LEFT			tgetstr("kl", NULL)
# define K_RIGHT		tgetstr("kr", NULL)
# define K_ENTER		tgetstr("cr", NULL)
# define K_QUIT			("q")

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Structures
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

typedef struct		s_ctx
{
	int				cols;
	int				rows;
	int				**grid;
	int				player;
	int				pieces;
	int				winner;
	int				victory;
	int				last;
	int				player_last;
	int				arrow;
}					t_ctx;

typedef struct		s_move
{
	int				cost;
	int				type;
	int				row;
	int				col;
	int				player;
	int				**grid;
	t_list			*childs;
}					t_move;

typedef struct		s_key
{
	char			*key;
	int				(*fn)(void);
}					t_key;

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Protos
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

t_ctx				*ft_get_ctx(void);

int					ft_error(char *err);
int					ft_strerror(void);
int					ft_err_size(void);

int					ft_malloc_grid(t_ctx *ctx);
void				ft_print_grid(int **grid);
int					ft_del_grid(int ***grid);

int					ft_play_on(t_ctx *ctx, int **grid, int col, int player);
int					ft_is_victorious(t_ctx *ctx, int x, int y);
int					ft_check(int **grid, int x, int y);
int					ft_unplay_on(int **grid, int col);
int					ft_unplay(t_ctx *ctx, int col);
int					ft_play(t_ctx *ctx, int col);
int					ft_player_play(t_ctx *ctx);
int					ft_ia_play(t_ctx *ctx);
int					ft_launch(char **av);
int					ft_loop(t_ctx *ctx);
int					ft_stop(t_ctx *ctx);
int					ft_win(t_ctx *ctx);

t_move				*ft_move_new(int type, int **grid, int row, int col);
int					ft_neighbours(t_ctx *ctx, t_move *move, int **grid);
int					ft_useless(t_ctx *ctx, t_move *move, int **grid);
int					ft_annoy(t_ctx *ctx, t_move *move, int **grid);
int					ft_get_score(t_ctx *ctx, t_move *move);
int					ft_minmax(t_ctx *ctx, t_move *move);
int					**ft_dup_grid(int **grid);
int					ft_is_empty(int **grid);

void				ft_notif(int cols, char *str, char *color);
void				ft_center(int pad, char *str);
int					ft_check_size(t_ctx *ctx);
void				ft_print_foots(int cols);
int					ft_reset_term(void);
int					ft_init_term(void);
void				ft_raw_term(void);
int					ft_putput(int c);
int					ft_get_fd(void);
void				ft_ascii(void);
void				ft_aff_arrow(void);

int					ft_treat_key(char *buf);
int					treat_key_right(void);
int					treat_key_left(void);
int					treat_key_enter(void);

#endif /* !AICU_H */
