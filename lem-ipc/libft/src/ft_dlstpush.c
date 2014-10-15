/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:07:55 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/01 17:48:51 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_dlstpush(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	if (*alst)
	{
		tmp = *alst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
		tmp->next->prev = tmp;
	}
	else
	{
		*alst = new;
	}
}
