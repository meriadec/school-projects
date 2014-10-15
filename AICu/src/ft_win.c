/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:54:30 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 18:12:00 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_win(t_ctx *ctx)
{
	(void) ctx;
	ctx->victory = 1;
	ft_print_grid(ctx->grid);
	if (ctx->winner == 1)
		ft_notif(ctx->cols, "You win !", "\033[7;36m");
	else if (ctx->winner == 2)
		ft_notif(ctx->cols, "IA win !", "\033[7;33m");
	else if (ctx->winner == 3)
		ft_notif(ctx->cols, "This is a draw :(", "\033[7;38m");
	return (OK);
}
