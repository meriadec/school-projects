/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_timeout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:37:19 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/09 17:40:36 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk.h"

void				ft_err_timeout(void)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putendl_fd("Connexion to server timeout... exiting.", 2);
	ft_putstr_fd("\033[0m", 2);
	exit(1);
}
