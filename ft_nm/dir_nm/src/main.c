/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/04/24 16:55:20 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int				main(int ac, char **av)
{
	int			ret;
	int			i;

	if (ac > 1)
	{
		i = 1;
		ret = OK;
		while (i < ac)
		{
			if (ERR == ft_nm(av[i], ac > 2))
				ret = ERR;
			++i;
		}
		return (ret);
	}
	else
		return (ft_nm("a.out", 0));
}
