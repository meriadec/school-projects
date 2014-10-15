/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 11:20:19 by mpillet           #+#    #+#             */
/*   Updated: 2014/04/25 12:41:51 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include "ft_otool.h"

int								ft_otool(char *file_name, int show_name)
{
	void						*buf;
	struct mach_header_64		*header;

	(void)show_name;
	if (NULL == (buf = ft_get_buf(file_name)))
		return (ERR);
	header = (struct mach_header_64 *)buf;
	if (header->magic != 4277009103)
		return (OK);
	ft_putstr(file_name);
	ft_putendl(":");
	ft_putendl("(__TEXT,__text) section");
	return (ft_loop_segments(header->ncmds, buf));
}
