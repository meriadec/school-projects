/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_opts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 16:49:13 by mpillet           #+#    #+#             */
/*   Updated: 2014/04/29 16:54:08 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_script.h"

int						ft_parse_error(char *opt)
{
	ft_putstr_fd("ft_script: err: Parse error near [", 2);
	ft_putstr_fd(opt, 2);
	ft_putendl_fd("]", 2);
	return (ERR);
}

int						ft_bad_option(char opt)
{
	ft_putstr_fd("ft_script: err: Unknown option [", 2);
	write(2, &opt, 1);
	ft_putendl_fd("]", 2);
	return (ERR);
}
