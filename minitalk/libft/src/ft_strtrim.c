/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:25:11 by mpillet           #+#    #+#             */
/*   Updated: 2014/01/04 19:29:16 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start_blanks(char const *s);
static int	get_end_blanks(char const *s, int end);

char		*ft_strtrim(char const *s)
{
	int		len;
	int		len_out;
	int		start_blanks;
	int		end_blanks;
	char	*out;

	out = NULL;
	if (s)
	{
		len = ft_strlen(s);
		start_blanks = get_start_blanks(s);
		end_blanks = get_end_blanks(s, len - 1);
		len_out = len - start_blanks - end_blanks;
		if (len_out < 0)
			len_out = 0;
		out = ft_strsub(s, start_blanks, len_out);
	}
	return (out);
}

int			get_start_blanks(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && ft_isblank(s[i]))
	{
		i++;
	}
	return (i);
}

int			get_end_blanks(char const *s, int end)
{
	int		nb;

	nb = 0;
	while (end >= 0 && ft_isblank(s[end]))
	{
		end--;
		nb++;
	}
	return (nb);
}
