/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:06:44 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/05 18:02:29 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
		if ((*alst)->next)
			(*alst)->next->prev = *alst;
	}
}
