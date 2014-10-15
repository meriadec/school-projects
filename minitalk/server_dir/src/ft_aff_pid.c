/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_pid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:54:20 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/08 18:07:10 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minitalk.h"

void			ft_aff_pid(void)
{
	ft_putstr("Server pid: ");
	ft_putstr("\033[0;35m");
	ft_putnbr(getpid());
	ft_putstr(" \033[0m");
	ft_putchar('\n');
	ft_putendl("--------------------");
	ft_putendl("Waiting for input...");
	ft_putendl("--------------------");
}
