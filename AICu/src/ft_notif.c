/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_notif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/03/09 12:37:32 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

void				ft_notif(int cols, char *str, char *color)
{
	int				pad;
	int				len;
	int				i;

	ft_putstr(color);
	len = (int) ft_strlen(str);
	pad = (cols * 2 + 4) / 2 - (len / 2);
	i = 0;
	while (i < pad)
	{
		ft_putchar(' ');
		++i;
	}
	ft_putstr(str);
	i += len;
	while (i < cols * 2 + 5)
	{
		ft_putchar(' ');
		++i;
	}
	ft_putstr("\033[0;0m\n");
	ft_putstr("\n");
}
