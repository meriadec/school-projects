/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:17:23 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/08 17:19:30 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk.h"

void			ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}