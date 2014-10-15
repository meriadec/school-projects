/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_play.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:15:03 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 18:19:19 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "aicu.h"

void				ft_place_cursor(t_ctx *ctx)
{
	int				i;

	if (-1 == ctx->arrow)
		ctx->arrow = ctx->cols / 2;
	i = 0;
	tputs(tgoto(tgetstr("cm", NULL), 3, 4), 1, ft_putput);
	while (i < ctx->arrow)
	{
		tputs(tgetstr("nd", NULL), 1, ft_putput);
		tputs(tgetstr("nd", NULL), 1, ft_putput);
		++i;
	}
	ft_aff_arrow();
}

static int			st_get_choice(t_ctx *ctx)
{
	char			buf[BUF_LEN + 1];

	ft_raw_term();
	ft_place_cursor(ctx);
	while (1)
	{
		ft_bzero(buf, BUF_LEN + 1);
		if (-1 == read(STDIN_FILENO, buf, BUF_LEN))
			return (ERR);
		if (0 == ft_strcmp(buf, K_ENTER) && !ctx->grid[0][ctx->arrow])
		{
			ft_reset_term();
			ctx->player_last = ctx->arrow;
			return (ft_play(ctx, ctx->player_last));
		}
		if (0 == ft_strcmp(buf, K_QUIT))
		{
			tputs(tgetstr("cl", NULL), 1, ft_putput);
			ft_reset_term();
			return (ERR);
		}
		ft_treat_key(buf);
	}
	ft_reset_term();
	return (OK);
}

int					ft_player_play(t_ctx *ctx)
{
	if (ERR == st_get_choice(ctx))
		return (ERR);
	return (OK);
}
