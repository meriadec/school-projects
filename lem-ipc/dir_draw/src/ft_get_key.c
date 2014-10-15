/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 14:40:43 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 13:09:43 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ipc.h>
#include <unistd.h>
#include "draw.h"

static void					st_add_prog_name(char **pwd, char *prog_name)
{
	char					*tmp1;
	char					*tmp2;

	tmp1 = ft_strjoin(*pwd, "/");
	ft_memdel((void **)pwd);
	tmp2 = ft_strjoin(tmp1, prog_name);
	ft_memdel((void **)&tmp1);
	*pwd = tmp2;
}

key_t						ft_get_key(void)
{
	t_ctx					*ctx;
	key_t					key;
	char					*pwd;

	ctx = ft_ctx();
	if (NULL == (pwd = getwd(NULL)))
		ft_error_exit("Can't getcwd");
	st_add_prog_name(&pwd, "lemipc");
	if (-1 == (key = ftok(pwd, 0)))
		ft_error_exit("Can't ftok");
	ft_memdel((void **)&pwd);
	return (key);
}
