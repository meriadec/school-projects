/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:54:45 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 10:26:41 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

/*
** Not really a minmax algorithm :)
*/
int					ft_minmax(t_ctx *ctx, t_move *move)
{
	if (move->type == TYPE_LEAF)
		return (ft_get_score(ctx, move));
	return (0);
}
