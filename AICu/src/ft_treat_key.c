/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:22:32 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 16:29:30 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int					ft_treat_key(char *buf)
{
	int				i;
	t_key			keys[NB_KEYS] =
	{
		{ K_LEFT, treat_key_left },
		{ K_RIGHT, treat_key_right }
	};

	i = 0;
	while (i < NB_KEYS)
	{
		if (0 == ft_strcmp(keys[i].key, buf))
			return (keys[i].fn());
		++i;
	}
	return (ERR);
}
