/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:59:38 by bgronon           #+#    #+#             */
/*   Updated: 2014/04/19 11:45:49 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_copy_tab(char ***dest, char **arr)
{
	int		i;
	int		len;

	i = 0;
	if (!arr)
		return ;
	len = ft_tab_len(arr);
	*dest = (char **)malloc(sizeof(char *) * (len + 1));
	while (arr && *arr)
	{
		(*dest)[i] = ft_strdup(*arr);
		++i;
		++arr;
	}
	(*dest)[i] = NULL;
}
