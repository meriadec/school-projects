/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by 5tta              #+#    #+#             */
/*   Updated: 2014/04/25 11:40:13 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int				ft_error(char *str)
{
	ft_putstr_fd("ft_otool: error: ", 2);
	ft_putendl_fd(str, 2);
	return (ERR);
}

void			*ft_nerror(char *str)
{
	ft_putstr_fd("ft_nm: error: ", 2);
	ft_putendl_fd(str, 2);
	return (NULL);
}
