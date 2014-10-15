/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:43:26 by mpillet           #+#    #+#             */
/*   Updated: 2013/12/12 16:32:37 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (list)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
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
