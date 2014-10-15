/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 12:02:59 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/01 19:12:28 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int					main(int ac, char **av, char **env)
{
	t_opt			*opts;

	opts = ft_get_opts();
	opts->env = env;
	if (ERR == ft_fill_opts(opts, ac, av))
		return (ERR);
	ft_find_shell(opts, env);
	if (ERR == ft_script(opts))
		return (ERR);
	return (OK);
}
