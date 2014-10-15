/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 10:46:00 by mpillet           #+#    #+#             */
/*   Updated: 2014/04/27 11:56:08 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include "ft_nm.h"

static char						st_find_char(struct segment_command_64 *segment,
		unsigned int index)
{
	struct section_64			*sect;

	sect = (struct section_64 *)((char *)segment
			+ sizeof(struct segment_command_64));
	sect += index;
	if (!ft_strcmp(segment->segname, "__DATA")
			&& !ft_strcmp(sect->sectname, "__bss"))
		return ('b');
	if (!ft_strcmp(segment->segname, "__DATA")
			&& !ft_strcmp(sect->sectname, "__data"))
		return ('d');
	if (!ft_strcmp(segment->segname, "__TEXT")
			&& !ft_strcmp(sect->sectname, "__text"))
		return ('t');
	return ('s');
}

static char						st_find(struct nlist_64 symbol, void *buf)
{
	struct load_command			*cmd;
	struct mach_header_64		*header;
	struct segment_command_64	*segment;
	unsigned int				i;
	unsigned int				n;

	header = (struct mach_header_64 *)buf;
	i = 0;
	n = 0;
	cmd = (struct load_command *)(((char *)buf)
			+ sizeof(struct mach_header_64));
	while (i < header->ncmds)
	{
		if (cmd->cmd == LC_SEGMENT_64)
		{
			segment = (struct segment_command_64 *)cmd;
			if (n + segment->nsects > symbol.n_sect)
				return (st_find_char(segment, symbol.n_sect - n - 1));
			n += segment->nsects;
		}
		cmd = (struct load_command *)(((char *)cmd) + cmd->cmdsize);
		++i;
	}
	return ('s');
}

static char						st_set_upper(char c, struct nlist_64 symbol)
{
	if ((symbol.n_type & N_EXT) && c != ' ')
		return (ft_toupper(c));
	return (c);
}

char							ft_get_type(struct nlist_64 symbol, void *buf)
{
	if ((symbol.n_type & N_TYPE) == N_SECT)
		return (st_set_upper(st_find(symbol, buf), symbol));
	if ((symbol.n_type & N_TYPE) == N_UNDF)
	{
		if (symbol.n_value == 0)
			return (st_set_upper('u', symbol));
		else
			return (st_set_upper('c', symbol));
	}
	if ((symbol.n_type & N_TYPE) == N_ABS)
		return (st_set_upper('a', symbol));
	if ((symbol.n_type & N_TYPE) == N_INDR)
		return (st_set_upper('i', symbol));
	return ('X');
}
