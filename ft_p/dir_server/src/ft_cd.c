/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 13:50:52 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 17:17:46 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "server.h"

static int					st_is_valid_path(t_ctx *ctx, char *path)
{
	char					*cur_path;
	char					*new_path;
	int						ret;

	(void)ctx;
	if (NULL == (cur_path = getcwd(NULL, 0)))
		return (ft_error_exit("Cant getcwd"));
	if (ERR == chdir(path))
	{
		ft_memdel((void **)&cur_path);
		return (FALSE);
	}
	if (NULL == (new_path = getcwd(NULL, 0)))
		return (ft_error_exit("Cant getcwd"));
	ret = ft_strncmp(new_path, ctx->root, ft_strlen(ctx->root)) == 0;
	if (ERR == chdir(cur_path))
		return (ft_error_exit("Fatal error, bro"));
	ft_memdel((void **)&cur_path);
	ft_memdel((void **)&new_path);
	return (ret);
}

static int					st_change_dir_to(t_ctx *ctx, char *path)
{
	char					*new_path;
	char					*tmp;

	if (!path)
		return (ft_send("Cant access (null) folder", STR_ERROR));
	ft_memdel((void **)&ctx->old_pwd);
	if (NULL == (ctx->old_pwd = getcwd(NULL, 0)))
		return (ft_error_exit("Cant getcwd"));
	if (ERR == chdir(path))
		return (ft_send("problem", STR_ERROR));
	if (NULL == (new_path = getcwd(NULL, 0)))
		return (ft_error_exit("Cant getcwd"));
	ft_memdel((void **)&ctx->pwd);
	tmp = ft_strsub(new_path, ft_strlen(ctx->root),
			ft_strlen(new_path) - ft_strlen(ctx->root));
	if (ft_strcmp(tmp, ""))
		ctx->pwd = tmp;
	else
	{
		ft_memdel((void **)&tmp);
		ctx->pwd = ft_strdup("/");
	}
	ft_send(ctx->pwd, STR_SUCCESS);
	return (OK);
}

int							ft_cd(t_ctx *ctx, char *cmd)
{
	char					**params;

	params = ft_str_super_split(cmd);
	if (!params[1])
	{
		ft_free_tab((void ***)&params);
		return (st_change_dir_to(ctx, ctx->root));
	}
	if (!ft_strcmp(params[1], "-"))
	{
		ft_free_tab((void ***)&params);
		return (st_change_dir_to(ctx, ctx->old_pwd));
	}
	if (!st_is_valid_path(ctx, params[1]))
	{
		ft_free_tab((void ***)&params);
		ft_send("Cant access folder.\n", STR_ERROR);
		return (ERR);
	}
	st_change_dir_to(ctx, params[1]);
	ft_free_tab((void ***)&params);
	return (OK);
}
