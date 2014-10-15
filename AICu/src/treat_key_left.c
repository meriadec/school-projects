/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_key_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 16:13:57 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 16:34:51 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					treat_key_left(void)
{
	t_ctx			*ctx;

	ctx = CTX;
	if (ctx->arrow > 0)
	{
		--ctx->arrow;
		tputs(tgetstr("dc", NULL), 1, ft_putput);
		tputs(tgetstr("le", NULL), 1, ft_putput);
		tputs(tgetstr("le", NULL), 1, ft_putput);
		ft_aff_arrow();
	}
	return (OK);
}
