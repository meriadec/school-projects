/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:54:26 by mpillet           #+#    #+#             */
/*   Updated: 2013/12/10 16:16:19 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	set_nb(char const *s, char c, int *nb);
static void	fill_tab(char const *s, char c, char **tab, int index);

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb;

	tab = NULL;
	if (s)
	{
		nb = 0;
		set_nb(s, c, &nb);
		tab = (char **) malloc(sizeof(char *) * (nb + 1));
		if (tab)
		{
			tab[nb] = NULL;
			fill_tab(s, c, tab, 0);
		}
	}
	return (tab);
}

static void	set_nb(char const *s, char c, int *nb)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (s[i1] != '\0')
	{
		if (i1 == i2 && s[i1] == c)
		{
			i1++;
			i2++;
		}
		else
		{
			if (s[i2] == c || s[i2] == '\0')
			{
				(*nb)++;
				i1 = i2;
			}
			else
				i2++;
		}
	}
}

static void	fill_tab(char const *s, char c, char **tab, int index)
{
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	while (s[i1] != '\0')
	{
		if (i1 == i2 && s[i1] == c)
		{
			i1++;
			i2++;
		}
		else
		{
			if (s[i2] == c || s[i2] == '\0')
			{
				tab[index++] = ft_strsub(s, i1, i2 - i1);
				i1 = i2;
			}
			else
				i2++;
		}
	}
}
