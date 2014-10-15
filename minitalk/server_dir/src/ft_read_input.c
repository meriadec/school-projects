/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 11:19:35 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/09 11:19:57 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void			ft_read_input(char c)
{
	t_input		*input;

	input = ft_get_input();
	if (input->i == 0)
		ft_bzero(input->c, 7);
	if (input->i < 7)
	{
		input->c[input->i] = c;
		++input->i;
	}
	else
	{
		ft_fill_char(input);
		input->i = 0;
	}
}
