/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 17:34:28 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/14 17:40:20 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"

static int					st_count(char **env)
{
	int						i;

	i = 0;
	while (env[i])
		++i;
	return (i);
}

char						**ft_dup_env(char **env)
{
	char					**res;
	int						i;

	if (!env)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (st_count(env) + 1))))
		return (ft_error_null("Can't malloc 'res'"));
	i = 0;
	while (env[i])
	{
		res[i] = ft_strdup(env[i]);
		++i;
	}
	res[i] = NULL;
	return (res);
}
