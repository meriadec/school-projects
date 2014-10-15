/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 18:29:53 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 18:39:36 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "aicu.h"

int					ft_check_size(t_ctx *ctx)
{
	struct winsize	w;
	int				fd;

	if (ERR == (fd = ft_get_fd()))
		return (ERR);
	if (-1 == ioctl(fd, TIOCGWINSZ, &w))
		return (ft_strerror());
	if (ctx->cols * 2 + 6 > w.ws_col)
		return (ft_error("The window is too small to display this grid"));
	return (OK);
}
