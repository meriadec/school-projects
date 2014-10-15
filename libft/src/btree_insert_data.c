/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 18:08:01 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/26 18:51:03 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *content, size_t content_size,
		int (*cmpf)(void *, void *))
{
	if (*root)
	{
		if (cmpf((*root)->content, content) == -1)
			btree_insert_data(&(*root)->left, content, content_size, cmpf);
		else
			btree_insert_data(&(*root)->right, content, content_size, cmpf);
	}
	else
		*root = btree_create_node(content, content_size);
}
