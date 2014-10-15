/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:57:45 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 15:01:42 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"

int							ft_light_error(char *msg, char *param)
{
	ft_putstr_fd(CLR_RED_R, 2);
	ft_putstr_fd("\n ", 2);
	ft_putstr_fd(msg, 2);
	if (param)
	{
		ft_putstr_fd(" '", 2);
		ft_putstr_fd(param, 2);
		ft_putstr_fd("'", 2);
	}
	ft_putstr_fd(" \n", 2);
	ft_putendl_fd(CLR_NONE, 2);
	return (ERR);
}

int							ft_error_exit(char *msg)
{
	ft_error(msg);
	exit(ERR);
}

int							ft_error(char *msg)
{
	ft_putstr_fd(CLR_RED_H, 2);
	ft_putstr_fd("\n ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" \n", 2);
	ft_putendl_fd(CLR_NONE, 2);
	return (ERR);
}

void						*ft_error_null(char *msg)
{
	ft_error(msg);
	return (NULL);
}
