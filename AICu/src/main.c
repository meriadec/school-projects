/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:32:45 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 07:55:01 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ERR == ft_launch(av))
			return (ERR);
	}
	else
		ft_putendl("usage: ./puissance4 <nb_rows> <nb_cols>");
	return (OK);
}
