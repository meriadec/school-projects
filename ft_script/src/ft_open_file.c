/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 17:17:14 by mpillet           #+#    #+#             */
/*   Updated: 2014/04/30 19:51:14 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_script.h"

int						ft_open_file(t_opt *opts)
{
	if (opts->a)
	{
		if (opts->file)
			opts->fd = open(opts->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			opts->fd = open("typescript", O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		if (opts->file)
			opts->fd = open(opts->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			opts->fd = open("typescript", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	return (OK);
}
