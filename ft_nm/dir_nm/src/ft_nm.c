/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/04/27 11:41:45 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include "ft_nm.h"

static off_t				st_get_size(int fd)
{
	struct stat				buf;

	if (-1 == fstat(fd, &buf))
		return (ft_error("Can't fstat file"));
	return (buf.st_size);
}

static void					*st_get_buf(char *file_name)
{
	int						fd;
	int						size;
	void					*buf;

	if (-1 == (fd = open(file_name, O_RDONLY)))
		return (ft_nerror("Can't read file"));
	if (ERR == (size = st_get_size(fd)))
		return (NULL);
	if (MAP_FAILED == (buf = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0)))
		return (ft_nerror("Can't mmap file"));
	return (buf);
}

t_list						*ft_get_list(void *buf,
		struct symtab_command *symtab)
{
	t_list					*lst;
	t_sym					cur;
	char					*strtable;
	struct nlist_64			*symbols;
	unsigned int			i;

	strtable = (char *)(((char *)buf) + symtab->stroff);
	symbols = (struct nlist_64 *)((char *)buf + symtab->symoff);
	lst = NULL;
	i = 0;
	while (i < symtab->nsyms)
	{
		if ('X' == (cur.type = ft_get_type(symbols[i], buf)))
		{
			++i;
			continue;
		}
		cur.name = &strtable[symbols[i].n_un.n_strx];
		cur.adr = ft_xlongtoa(symbols[i].n_value);
		ft_lstadd(&lst, ft_lstnew(&cur, sizeof(t_sym)));
		++i;
	}
	return (lst);
}

void						st_show(t_list *lst, int print_name, char *name)
{
	if (print_name)
	{
		ft_putchar('\n');
		ft_putstr(name);
		ft_putendl(":");
	}
	while (lst)
	{
		if (SYMB->type == 'u' || SYMB->type == 'U')
			ft_putstr("                ");
		else if (0 == ft_strcmp("0", SYMB->adr))
			ft_putstr("0000000000000000");
		else
			ft_printpad(SYMB->adr);
		ft_putstr(" ");
		ft_putchar(SYMB->type);
		ft_putstr(" ");
		ft_putendl(SYMB->name);
		lst = lst->next;
	}
}

int							ft_nm(char *file_name, int print_name)
{
	void					*buf;
	struct mach_header_64	*header;
	struct symtab_command	*symtab;
	t_list					*lst;

	if (NULL == (buf = st_get_buf(file_name)))
		return (ERR);
	header = (struct mach_header_64 *)buf;
	if (header->magic != 4277009103)
		return (OK);
	if (NULL == (symtab = ft_get_sym_tab(header->ncmds, buf)))
		return (ft_error("Can't find sym tab"));
	if (NULL == (lst = ft_get_list(buf, symtab)))
		return (ERR);
	ft_lstsort(lst, ft_order);
	st_show(lst, print_name, file_name);
	return (OK);
}
