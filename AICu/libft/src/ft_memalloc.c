/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:43:56 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/25 11:01:15 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = NULL;
	if (size)
	{
		mem = (void *) malloc(size);
		if (mem)
		{
			ft_bzero(mem, size);
		}
	}
	return (mem);
}
