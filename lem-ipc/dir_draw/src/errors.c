/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 11:43:26 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 12:59:32 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "draw.h"

int						ft_error(char *str)
{
	ft_putstr_fd("\033[0;31merror: ", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[0m", 2);
	return (ERR);
}

void					ft_error_exit(char *str)
{
	ft_error(str);
	ft_exit();
}

void					ft_exit(void)
{
	exit(ERR);
}
