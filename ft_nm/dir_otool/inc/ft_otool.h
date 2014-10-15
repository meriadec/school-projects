/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/04/27 11:49:34 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# define OK			0
# define ERR		1

# define TRUE		1
# define FALSE		0

# include <mach-o/loader.h>
# include "libft.h"

int								ft_otool(char *file_name, int show_name);
void							*ft_get_buf(char *file_name);
int								ft_loop_segments(unsigned int ncmds, void *buf);
char							*ft_xlongtoa(long unsigned int n);
void							ft_show(struct section_64 *sect, void *buf);

int								ft_error(char *str);
void							*ft_nerror(char *str);
void							ft_printpad(char *str);

#endif
