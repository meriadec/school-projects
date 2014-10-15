/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 18:24:26 by mpillet           #+#    #+#             */
/*   Updated: 2014/06/01 19:23:46 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/shm.h>
#include "lemipc.h"

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
			if (MAP[y][x])
				ft_putnbr(MAP[y][x]);
			else
				ft_putchar('.');
			ft_putchar(' ');
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}
