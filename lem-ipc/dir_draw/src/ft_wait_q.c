/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_q.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 15:32:24 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/29 13:06:47 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "draw.h"

void						ft_wait_q(void)
{
	char					buf[BUF_SIZE];

	ft_bzero(buf, BUF_SIZE);
	while (0 != read(0, buf, BUF_SIZE - 1))
	{
		if (0 == ft_strcmp(buf, "q\n"))
			break ;
		ft_bzero(buf, BUF_SIZE);
	}
}
