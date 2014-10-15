/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 18:31:16 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 18:31:36 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "aicu.h"

int					ft_get_fd(void)
{
	static int		fd = -1;

	if (fd == -1)
	{
		fd = open("/dev/tty", O_RDWR);
		if (fd == -1)
			return (ft_error("failed to open /dev/tty"));
	}
	return (fd);
}
