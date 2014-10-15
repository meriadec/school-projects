/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 15:45:48 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 15:46:38 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int							ft_is_cd(char *str)
{
	if (0 == ft_strcmp(str, "cd"))
		return (TRUE);
	if (ft_startswith(str, "cd") && (str[2] == ' ' || str[2] == '\t'))
		return (TRUE);
	return (FALSE);
}
