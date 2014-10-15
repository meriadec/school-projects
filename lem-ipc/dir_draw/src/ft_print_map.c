/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 18:24:26 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 14:41:32 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include "draw.h"

void						ft_print_map(void)
{
	t_ctx					*ctx;
	int						y;
	int						x;

	ctx = ft_ctx();
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			ft_putnbr(ctx->shared->map[y][x]);
			ft_putchar(' ');
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}
