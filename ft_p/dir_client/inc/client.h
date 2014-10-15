/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:26:08 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 17:23:12 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Defines
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

# define OK					0
# define ERR				-1
# define TRUE				1
# define FALSE				0

# define BUF_LEN			2048
# define PROMPT				"FTP"

# define CLR_RED_R			"\033[0;31m"
# define CLR_RED_H			"\033[7;31m"
# define CLR_NONE			"\033[0m"

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Structures
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

typedef struct				s_ctx
{
	char					*addr;
	int						port;
	int						sock;
	char					*pwd;
}							t_ctx;

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Prototypes
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

/*
** Error / Success
*/

int							ft_usage(char *name);
int							ft_error(char *msg);
int							ft_light_error(char *msg, char *param);
int							ft_success(char *str);

/*
** Context
*/

t_ctx						*ft_ctx(void);
int							ft_clear(void);

/*
** Core
*/

int							ft_create_client(void);
int							ft_read(void);
int							ft_is_valid(char **str);
void						ft_prompt(void);
int							ft_is_cd(char *str);

#endif
