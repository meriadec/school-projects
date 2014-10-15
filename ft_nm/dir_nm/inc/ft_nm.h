/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/04/24 16:54:00 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# define OK			0
# define ERR		1

# define TRUE		1
# define FALSE		0

# define SYMB		((t_sym *) lst->content)

# include <mach-o/nlist.h>
# include "libft.h"

typedef struct				s_sym
{
	char					*name;
	void					*adr;
	char					type;
}							t_sym;

int							ft_nm(char *file_name, int print_name);
struct symtab_command		*ft_get_sym_tab(unsigned int ncmds, void *buf);
char						ft_get_type(struct nlist_64 symbol, void *buf);

int							ft_error(char *str);
void						*ft_nerror(char *str);
char						*ft_xlongtoa(long unsigned int n);
void						ft_printpad(char *str);
int							ft_order(t_list *node1, t_list *node2);

#endif
