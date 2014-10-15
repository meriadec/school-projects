/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_segments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 12:01:53 by mpillet           #+#    #+#             */
/*   Updated: 2014/04/27 11:43:03 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include "ft_otool.h"

static struct section_64		*st_get_text_section(
		struct segment_command_64 *segment)
{
	struct section_64			*sect;
	unsigned int				i;

	sect = (struct section_64 *)((char *)segment
			+ sizeof(struct segment_command_64));
	i = 0;
	while (i < segment->nsects)
	{
		if (!ft_strcmp(sect->sectname, "__text"))
			return (sect);
		++i;
		++sect;
	}
	return (NULL);
}

int								ft_loop_segments(unsigned int ncmds, void *buf)
{
	struct load_command			*cmd;
	struct segment_command_64	*segment;
	struct section_64			*sect;
	unsigned int				i;

	i = 0;
	cmd = (struct load_command *)(((char *)buf)
			+ sizeof(struct mach_header_64));
	while (i < ncmds)
	{
		if (cmd->cmd == LC_SEGMENT_64)
		{
			segment = (struct segment_command_64 *)cmd;
			if (NULL != (sect = st_get_text_section(segment)))
			{
				ft_show(sect, buf);
				break ;
			}
		}
		cmd = (struct load_command *)(((char *)cmd) + cmd->cmdsize);
		++i;
	}
	return (OK);
}
