/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:06:02 by mpillet           #+#    #+#             */
/*   Updated: 2014/01/04 15:10:48 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist		*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist		*list;

	list = (t_dlist *) malloc(sizeof(t_dlist));
	if (list)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		list->prev = NULL;
		if (content && content_size)
		{
			list->content_size = content_size;
			list->content = malloc(list->content_size);
			if (list->content)
				ft_memcpy(list->content, content, content_size);
		}
	}
	return (list);
}
