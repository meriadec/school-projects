/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 18:24:37 by mpillet           #+#    #+#             */
/*   Updated: 2014/01/23 18:35:49 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_print(t_btree *root, char *type, int level)
{
	int		cpt;

	if (root)
	{
		cpt = 0;
		while (cpt < level)
		{
			ft_putstr("    ");
			++cpt;
		}
		ft_putstr("[");
		ft_putstr(type);
		ft_putstr(" ");
		ft_putstr((char *) root->item);
		ft_putstr("]\n");
		btree_print(root->left, "LEFT", level + 1);
		btree_print(root->right, "RIGHT", level + 1);
	}
}
