/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 11:18:42 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/09 11:18:56 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void			ft_fill_char(t_input *input)
{
	char		c;

	c = (input->c[6] << 6
			| input->c[5] << 5
			| input->c[4] << 4
			| input->c[3] << 3
			| input->c[2] << 2
			| input->c[1] << 1
			| input->c[0] << 0);
	if (c == '\004')
	{
		ft_output(input->msg);
		input->i = 0;
		input->saved = 0;
		input->buf_len = 0;
		ft_memdel((void **) &input->msg);
	}
	else
		ft_realloc(input, c, NULL);
}
