/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 16:19:24 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 16:56:21 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

void				ft_aff_arrow(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->grid[0][ctx->arrow])
		ft_putstr("\033[0;31m");
	else
		ft_putstr("\033[0;36m");
	ft_putstr("▼");
	ft_putstr("\033[0;0m");
	tputs(tgetstr("le", NULL), 1, ft_putput);
}
