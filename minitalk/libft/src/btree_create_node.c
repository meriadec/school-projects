/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:15:33 by mpillet           #+#    #+#             */
/*   Updated: 2014/01/23 18:10:55 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree		*btree_create_node(void *item)
{
	t_btree		*node;

	if (!(node = (t_btree *) malloc(sizeof(t_btree))))
		return (NULL);
	node->parent = NULL;
	node->right = NULL;
	node->left = NULL;
	node->item = item;
	return (node);
}
