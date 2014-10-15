/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 12:09:42 by mpillet           #+#    #+#             */
/*   Updated: 2014/04/27 11:48:59 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mach-o/loader.h>
#include "ft_otool.h"

void							st_show_line(unsigned char *mem,
		uint64_t i, uint64_t size, uint64_t addr)
{
	uint64_t					y;
	char						*tmp;

	y = 0;
	ft_printpad(ft_xlongtoa(addr + i));
	ft_putchar(' ');
	while (y < 16 && i < size)
	{
		tmp = ft_xlongtoa(mem[i]);
		if (ft_strlen(tmp) < 2)
			ft_putchar('0');
		ft_putstr(tmp);
		free(tmp);
		ft_putchar(' ');
		++y;
		++i;
	}
	ft_putchar('\n');
}

void							ft_show(struct section_64 *sect, void *buf)
{
	uint64_t					i;
	uint64_t					addr;
	unsigned char				*mem;

	addr = sect->addr;
	mem = (unsigned char *)((char *)buf + sect->offset);
	i = 0;
	while (i < sect->size)
	{
		st_show_line(mem, i, sect->size, addr);
		i += 16;
	}
}
