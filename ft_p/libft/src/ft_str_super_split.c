/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_super_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 14:03:46 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 14:06:01 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	set_nb(char const *s, int *nb)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (s[i1] != '\0')
	{
		if (i1 == i2 && (s[i1] == ' ' || s[i1] == '\t'))
		{
			i1++;
			i2++;
		}
		else
		{
			if (s[i2] == '\t' || s[i2] == ' ' || s[i2] == '\0')
			{
				(*nb)++;
				i1 = i2;
			}
			else
				i2++;
		}
	}
}

static void	fill_tab(char const *s, char **tab, int index)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (s[i1] != '\0')
	{
		if (i1 == i2 && (s[i1] == ' ' || s[i1] == '\t'))
		{
			i1++;
			i2++;
		}
		else
		{
			if (s[i2] == '\t' || s[i2] == ' ' || s[i2] == '\0')
			{
				tab[index++] = ft_strsub(s, i1, i2 - i1);
				i1 = i2;
			}
			else
				i2++;
		}
	}
}

char		**ft_str_super_split(char const *s)
{
	char	**tab;
	int		nb;

	tab = NULL;
	if (s)
	{
		nb = 0;
		set_nb(s, &nb);
		tab = (char **)malloc(sizeof(char *) * (nb + 1));
		if (tab)
		{
			tab[nb] = NULL;
			fill_tab(s, tab, 0);
		}
	}
	return (tab);
}
