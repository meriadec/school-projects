/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:15:33 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/27 21:38:56 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree		*btree_create_node(void *content, size_t content_size)
{
	t_btree		*node;

	if (!(node = (t_btree *) malloc(sizeof(t_btree))))
		return (NULL);
	node->parent = NULL;
	node->right = NULL;
	node->left = NULL;
	node->content = NULL;
	node->content_size = 0;
	if (content && content_size)
	{
		node->content = malloc(content_size);
		if (node->content)
			ft_memcpy(node->content, content, content_size);
	}
	return (node);
}
