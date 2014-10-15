/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sym_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 13:09:21 by mpillet           #+#    #+#             */
/*   Updated: 2014/04/24 10:36:08 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include "ft_nm.h"

struct symtab_command		*ft_get_sym_tab(unsigned int ncmds, void *buf)
{
	struct load_command		*cmd;
	unsigned int			i;

	i = 0;
	cmd = (struct load_command *)(((char *)buf)
			+ sizeof(struct mach_header_64));
	while (i < ncmds)
	{
		if (cmd->cmd == LC_SYMTAB)
			return ((struct symtab_command *)cmd);
		cmd = (struct load_command *)(((char *)cmd) + cmd->cmdsize);
		++i;
	}
	return (NULL);
}
