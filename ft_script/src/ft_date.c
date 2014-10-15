/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 18:01:57 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 18:13:05 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include "ft_script.h"

void					ft_date(int fd)
{
	struct timeval		tp;
	char				*res;

	if (-1 == gettimeofday(&tp, NULL))
		return ;
	res = ctime(&tp.tv_sec);
	write(fd, res, ft_strlen(res));
}
