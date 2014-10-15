/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_foots.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 17:07:34 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static void			st_print_other(int cols)
{
	int				i;

	i = 0;
	ft_putstr("\n \033[7;39m \033[7;0m");
	while (i < cols)
	{
		ft_putstr("  ");
		++i;
	}
	ft_putstr(" \033[7;39m \033[7;0m");
	i = 0;
	ft_putstr("\n\033[7;39m   \033[7;0m");
	while (i < (cols * 2) - 1)
	{
		ft_putstr(" ");
		++i;
	}
	ft_putstr("\033[7;39m   \033[7;0m\n");
}

void				ft_print_foots(int cols)
{
	ft_putstr("\033[7;39m \033[7;0m ");
	st_print_other(cols);
}
