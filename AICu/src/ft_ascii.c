/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 12:40:05 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

void				ft_ascii(void)
{
	t_ctx			*ctx;
	int				pad;
	char			*str;

	ctx = CTX;
	pad = (ctx->cols * 2 + 4) / 2 - 14;
	ft_putstr(" \n");
	str = ft_strjoin("\033[7;32m AI-Cu \033[0;0m - ",
			"\033[1;32mConnect 4 simulator\033[1;0m");
	ft_center(pad, "\033[2;30m-----------------------------\033[1;0m");
	ft_center(pad, str);
	ft_memdel((void **) &str);
	ft_center(pad, "\033[2;30m-----------------------------\033[1;0m");
	ft_putstr(" \n");
	ft_putstr("\033[0;0m");
}
