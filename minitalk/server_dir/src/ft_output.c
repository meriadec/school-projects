/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 18:08:00 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/08 18:10:10 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void				ft_output(char *str)
{
	ft_putstr("\033[0;34m");
	ft_putstr("Input received: ");
	ft_putstr("\033[0m[");
	ft_putstr(str);
	ft_putendl("]");
}
