/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 18:22:48 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 18:29:02 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int						ft_find_shell(t_opt *opts, char **env)
{
	int					i;

	i = 0;
	opts->shell = NULL;
	while (env[i])
	{
		if (ft_startswith(env[i], "SHELL="))
		{
			opts->shell = env[i] + 6;
			return (OK);
		}
		++i;
	}
	opts->shell = "/bin/bash";
	return (OK);
}
