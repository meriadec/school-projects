/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trunc_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:06:49 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/04 15:07:12 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_trunc_tab(char ***arr, int nb)
{
	char	**new;
	int		i;
	int		len;

	len = ft_tab_len(*arr) - nb;
	if (len > 0)
	{
		new = (char **) malloc(sizeof(char *) * (len + 1));
		if (new)
		{
			i = 0;
			while (*arr && (*arr)[i + nb])
			{
				new[i] = ft_strdup((*arr)[i + nb]);
				++i;
			}
			new[i] = NULL;
			ft_free_tab((void ***)arr);
			*arr = new;
		}
	}
}
