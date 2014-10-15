/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 14:30:10 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/31 12:03:37 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "lemipc.h"

static void					st_msg(int team, int x, int y)
{
	char					*str_team;
	char					*str_x;
	char					*str_y;
	char					*tmp1;
	char					*tmp2;

	str_team = ft_itoa(team);
	str_x = ft_itoa(x);
	str_y = ft_itoa(y);
	tmp1 = ft_strjoin("\nYou have been placed in ", str_x);
	tmp2 = ft_strjoin(tmp1, "x");
	ft_memdel((void **)&tmp1);
	tmp1 = ft_strjoin(tmp2, str_y);
	ft_memdel((void **)&tmp2);
	tmp2 = ft_strjoin(tmp1, " (team ");
	ft_memdel((void **)&tmp1);
	tmp1 = ft_strjoin(tmp2, str_team);
	ft_memdel((void **)&tmp2);
	tmp2 = ft_strjoin(tmp1, ")\n");
	ft_putendl(tmp2);
	ft_memdel((void **)&tmp1);
	ft_memdel((void **)&tmp2);
	ft_memdel((void **)&str_team);
	ft_memdel((void **)&str_x);
	ft_memdel((void **)&str_y);
}

void						ft_place(void)
{
	t_ctx					*ctx;

	srand(time(NULL));
	ctx = ft_ctx();
	POSX = rand() % W;
	POSY = rand() % H;
	while (MAP[POSY][POSX] != 0)
	{
		POSX = rand() % W;
		POSY = rand() % H;
	}
	MAP[POSY][POSX] = ctx->team;
	st_msg(ctx->team, POSX, POSY);
}
