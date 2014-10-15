/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 13:03:48 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 17:50:23 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

void					ft_error(char *str)
{
	ft_reset_term();
	ft_putstr_fd("philo: error: ", 2);
	ft_putendl_fd(str, 2);
	exit(ERR);
}
