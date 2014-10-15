/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:27:54 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/16 19:24:04 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "server.h"

int							ft_ls(t_ctx *ctx)
{
	DIR						*dirp;
	struct dirent			*dp;
	char					*res;
	char					*tmp;
	char					*tmp2;

	(void)ctx;
	res = NULL;
	if (NULL == (dirp = opendir(".")))
		return (ERR);
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp = ft_strjoin(dp->d_name, "\n");
		tmp2 = ft_strjoin(res, tmp);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&res);
		res = tmp2;
	}
	closedir(dirp);
	ft_send(res, STR_SUCCESS);
	return (OK);
}
