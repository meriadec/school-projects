/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:29:44 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/18 17:23:12 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

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

# define CLR_RED_R			"\033[0;31m"
# define CLR_RED_H			"\033[7;31m"
# define CLR_NONE			"\033[0m"

# define STR_SUCCESS		"\033[7;32m SUCCESS \033[0m"
# define STR_ERROR			"\033[7;31m ERROR \033[0m"

# define BUF_LEN			2048

/*
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** Structures
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

typedef struct				s_ctx
{
	int						port;
	int						sock;
	char					**env;
	char					*root;
	char					*pwd;
	char					*old_pwd;
	int						cs;
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
void						*ft_error_null(char *msg);
int							ft_error_exit(char *msg);
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

int							ft_create_server(void);
int							ft_close_server(void);
int							ft_serve(void);
char						**ft_dup_env(char **env);
int							ft_treat(char *cmd);
int							ft_send(char *str, char *ret);

/*
** Builtins
*/

int							ft_ls(t_ctx *ctx);
int							ft_cd(t_ctx *ctx, char *cmd);
int							ft_pwd(t_ctx *ctx);

#endif
