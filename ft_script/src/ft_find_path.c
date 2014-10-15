/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:59:52 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 20:03:01 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_script.h"

static char				*st_extract(char *src, char *dest)
{
	int					i;

	ft_bzero(dest, 4096);
	i = 0;
	while (src[i] && src[i] != ':')
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}

void					st_join(char *path, char *cmd)
{
	int					i;
	int					y;

	i = ft_strlen(path);
	y = 0;
	path[i++] = '/';
	while (cmd[y])
	{
		path[i] = cmd[y];
		++i;
		++y;
	}
}

static int				st_simple_cmd(t_opt *opts, char *cmd)
{
	if (0 == access(opts->cmd[0], X_OK))
	{
		ft_strcpy(cmd, opts->cmd[0]);
		return (OK);
	}
	else
		return (ERR);
}

int						ft_find_path(t_opt *opts, char *cmd)
{
	char				*path;
	char				tmp[4096];
	int					len;
	int					i;

	if (-1 != ft_indexof(opts->cmd[0], '/'))
		return (st_simple_cmd(opts, cmd));
	if (NULL == (path = ft_get_path(opts)))
		return (ERR);
	i = 0;
	while (path[i])
	{
		len = ft_nb_until_next(&(path[i]));
		st_join(st_extract(&(path[i]), tmp), opts->cmd[0]);
		if (0 == access(tmp, X_OK))
		{
			ft_strcpy(cmd, tmp);
			return (OK);
		}
		i += len;
	}
	return (ERR);
}
