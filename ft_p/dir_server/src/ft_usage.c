/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:48:58 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/12 17:05:52 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int							ft_usage(char *name)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(" <port>", 2);
	return (ERR);
}
