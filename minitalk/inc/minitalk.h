/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 13:34:13 by mpillet           #+#    #+#             */
/*   Updated: 2014/02/09 17:40:22 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"

# define BUF_LEN		1024

typedef struct		s_input
{
	char			c[7];
	char			*msg;
	int				i;
	int				buf_len;
	int				saved;
}					t_input;

void			ft_error(char *str);
void			ft_realloc(t_input *input, char c, char *tmp);
t_input			*ft_get_input(void);
void			ft_aff_pid(void);
void			ft_output(char *str);
void			ft_fill_char(t_input *input);
void			ft_read_input(char c);
void			ft_err_timeout(void);

#endif
