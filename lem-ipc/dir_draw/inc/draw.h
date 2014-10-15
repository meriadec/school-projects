/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 12:46:56 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 15:49:07 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

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

# define MLX				(ctx->w.mlx)
# define WIN				(ctx->w.win)
# define IMG				(ctx->w.img)
# define DAT    			(d->data_add)
# define SIZ    			(d->size)
# define BPP    			(d->bpp)

# define OFFSET				30

# define WIDTH				(W * 10 + OFFSET * 2)
# define HEIGHT				(H * 10 + OFFSET * 2)

# define CUR				MAP[y][x]

/*
** ----------------------------------------------------------------------------
** Structures
** ----------------------------------------------------------------------------
*/

typedef struct				s_win
{
	void					*mlx;
	void					*win;
	void					*img;
}							t_win;

typedef struct				s_dat
{
	char					*data_add;
	int						endian;
	int						bpp;
	int						size;
}							t_data;

typedef struct				s_pix
{
	int						x;
	int						y;
}							t_pix;

typedef struct				s_rgb
{
	int						r;
	int						g;
	int						b;
}							t_rgb;

typedef struct				s_ctx
{
	int						segment_id;
	key_t					shm_key;
	int						page_size;
	t_shared				*shared;
	t_win					w;
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

/*
** Core
*/

int							ft_get_shared_mem(void);
int							ft_create_shared_mem(void);
key_t						ft_get_key(void);
int							key_hook(int keycode, t_ctx *ctx);
int							ft_loop(t_ctx *ctx);
void						ft_pixel(t_ctx *ctx, t_pix p, t_rgb col);
void						ft_draw(t_ctx *ctx);
void						ft_draw_cell(int num, int posx, int posy);
t_rgb						ft_get_color_by_team(int team);

/*
** Errors
*/

int							ft_error(char *str);
void						ft_error_exit(char *str);
void						ft_exit(void);

/*
** Utils
*/

void						ft_wait_q(void);
void						ft_print_map(void);

#endif
