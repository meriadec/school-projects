/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:40:30 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 07:55:12 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "aicu.h"

int					ft_error(char *err)
{
	ft_putstr_fd("\033[0;31m ✘ ", 2);
	ft_putendl_fd(err, 2);
	ft_putstr_fd("\033[0m", 2);
	return (ERR);
}

int					ft_strerror(void)
{
	ft_putchar('\n');
	ft_error(strerror(errno));
	return (ERR);
}

int					ft_err_size(void)
{
	char			*s1;
	char			*s2;

	s1 = ft_strjoin("Map must have at least ", ft_itoa(ROWS_MIN));
	s2 = ft_strjoin(s1, " rows and ");
	ft_memdel((void **) &s1);
	s1 = ft_strjoin(s2, ft_itoa(COLS_MIN));
	ft_memdel((void **) &s2);
	s2 = ft_strjoin(s1, " columns.");
	ft_error(s2);
	ft_memdel((void **) &s2);
	return (ERR);
}
