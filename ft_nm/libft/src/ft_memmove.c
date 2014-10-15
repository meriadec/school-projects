/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:09:10 by mpillet           #+#    #+#             */
/*   Updated: 2013/11/25 10:58:21 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*cpy;

	cpy = malloc(n);
	ft_memcpy(cpy, s2, n);
	ft_memcpy(s1, cpy, n);
	free(cpy);
	return (s1);
}
