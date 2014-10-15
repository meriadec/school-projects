/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:52:44 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/08 17:53:04 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minitalk.h"

t_input			*ft_get_input(void)
{
	static t_input		*input = NULL;

	if (NULL == input)
	{
		if (!(input = (t_input *) malloc(sizeof(t_input))))
		{
			ft_putendl_fd("Can't malloc input struct", 2);
			exit(1);
		}
		input->msg = NULL;
		input->i = 0;
		input->buf_len = 0;
		input->saved = 0;
	}
	return (input);
}
