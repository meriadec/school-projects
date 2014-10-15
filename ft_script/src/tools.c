/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 19:45:50 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 19:47:14 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

char					*ft_get_path(t_opt *opts)
{
	int					i;

	i = 0;
	while (opts->env[i])
	{
		if (ft_startswith(opts->env[i], "PATH="))
			return (opts->env[i] + 5);
		++i;
	}
	return (NULL);
}

int						ft_nb_until_next(char *str)
{
	int					i;
	static int			first = 1;

	i = 1;
	while (str[i] && str[i] != ':')
		++i;
	if (!first && str[i])
		i += 1;
	first = 0;
	if (str[i] == ':')
		i += 1;
	return (i);
}
