/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_opts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 12:13:59 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 16:39:30 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "ft_script.h"

static int				st_acquire_opt(char *opt, t_opt *opts)
{
	int					i;
	int					len;

	i = 0;
	len = ft_strlen(opt);
	while (i < len)
	{
		if (opt[i] == 'a')
			opts->a = TRUE;
		else if (opt[i] == 'q')
			opts->q = TRUE;
		else
			return (ft_bad_option(opt[i]));
		++i;
	}
	return (OK);
}

static int				st_acquire_file(char *file, t_opt *opts)
{
	if (0 == access(file, W_OK) || ENOENT == errno)
	{
		opts->file = file;
		return (OK);
	}
	ft_putendl_fd("ft_script: err: Can't write to file.", 2);
	return (ERR);
}

static int				st_treat_arg(char *arg, t_opt *opts)
{
	if (ft_startswith(arg, "-") && ft_strlen(arg) > 1)
	{
		if (ERR == st_acquire_opt(arg + 1, opts))
			return (ERR);
	}
	else
	{
		if (ERR == st_acquire_file(arg, opts))
			return (ERR);
		return (CMD_TURN);
	}
	return (OK);
}

int						ft_fill_opts(t_opt *opts, int ac, char **av)
{
	int					i;
	int					opts_turn;
	int					ret;

	opts->a = FALSE;
	opts->q = FALSE;
	opts->file = "typescript";
	opts->cmd = NULL;
	i = 1;
	opts_turn = 1;
	while (i < ac)
	{
		if (ERR == (ret = st_treat_arg(av[i], opts)))
			return (ERR);
		if (CMD_TURN == ret)
		{
			if (i + 1 < ac)
				opts->cmd = &av[i + 1];
			break ;
		}
		++i;
	}
	return (OK);
}
