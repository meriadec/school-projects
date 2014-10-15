/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:50:33 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/08 17:51:32 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk.h"

void			ft_realloc(t_input *input, char c, char *tmp)
{
	if (NULL == input->msg)
	{
		if (!(input->msg = (char *) malloc(sizeof(char) * (BUF_LEN + 1))))
			ft_error("Can't malloc 'input->msg'");
		ft_bzero(input->msg, BUF_LEN + 1);
		input->msg[0] = c;
		input->buf_len = BUF_LEN;
		input->saved = 1;
	}
	else
	{
		if (input->saved + 1 > input->buf_len)
		{
			if (!(tmp = (char *) malloc(sizeof(char)
							* (input->buf_len + BUF_LEN + 1))))
				ft_error("Can't malloc 'tmp'");
			ft_bzero(tmp, input->buf_len + BUF_LEN + 1);
			ft_memcpy(tmp, input->msg, input->saved);
			ft_memdel((void **) &input->msg);
			input->msg = tmp;
			input->buf_len += BUF_LEN;
		}
		input->msg[input->saved] = c;
		++input->saved;
	}
}
