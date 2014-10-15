/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 13:01:35 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 16:23:31 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

t_env					*ft_getenv(void)
{
	static t_env		*env = NULL;

	if (NULL == env)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env))))
			ft_error("Can't malloc 'env'");
		env->death = 0;
	}
	return (env);
}
