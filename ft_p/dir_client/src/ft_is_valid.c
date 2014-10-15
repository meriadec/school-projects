/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 16:42:44 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 15:46:35 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int							ft_is_valid(char **str)
{
	*str = ft_strtrim(*str);
	if (!ft_strcmp(*str, ""))
		return (FALSE);
	if (ft_strcmp(*str, "ls")
			&& ft_strcmp(*str, "quit")
			&& ft_strcmp(*str, "pwd")
			&& !ft_is_cd(*str))
	{
		ft_light_error("Invalid command", *str);
		return (FALSE);
	}
	return (TRUE);
}
