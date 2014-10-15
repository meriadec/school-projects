/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:50:47 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/02 23:42:30 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*tmp;

	while (*alst)
	{
		tmp = (*alst)->next;
		ft_dlstdelone(alst, del);
		*alst = tmp;
	}
}
