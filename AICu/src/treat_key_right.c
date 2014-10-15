/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 16:14:19 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 16:34:57 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					treat_key_right(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->arrow < ctx->cols - 1)
	{
		++ctx->arrow;
		tputs(tgetstr("dc", NULL), 1, ft_putput);
		tputs(tgetstr("nd", NULL), 1, ft_putput);
		tputs(tgetstr("nd", NULL), 1, ft_putput);
		ft_aff_arrow();
	}
	return (OK);
}
