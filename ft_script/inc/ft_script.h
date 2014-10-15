/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/28 12:04:24 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 20:04:12 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

/*
** Includes
*/

# include <termios.h>
# include <signal.h>
# include "libft.h"

/*
** Defines
*/

# define OK				0
# define ERR			1

# define FALSE			0
# define TRUE			1

# define CMD_TURN		42

/*
** Structures
*/

typedef struct			s_opt
{
	int					fd;
	int					a;
	int					q;
	char				*file;
	char				**cmd;
	char				*shell;
	int					master;
	int					slave;
	char				**env;
	int					zombi;
	struct termios		term;
}						t_opt;

/*
** Prototypes
*/

t_opt					*ft_get_opts(void);

int						ft_script(t_opt *opts);

int						ft_fill_opts(t_opt *opts, int ac, char **av);
int						ft_find_shell(t_opt *opts, char **env);
int						ft_parse_error(char *opt);
int						ft_bad_option(char opt);

int						ft_open_file(t_opt *opts);
void					ft_date(int fd);
int						ft_get_master_and_slave(t_opt *opts);
int						ft_shell(t_opt *opts);
int						ft_cmd(t_opt *opts);
int						ft_find_path(t_opt *opts, char *cmd);
int						ft_io(t_opt *opts, int pid_child);

void					ft_raw();
void					ft_reset_term(t_opt *opts);
int						ft_tcsetattr(int fd, struct termios *t);
int						ft_tcgetattr(int fd, struct termios *t);

sig_t					ft_signal(int s, void (*func)(int));
void					ft_end(int pid);
void					ft_sig_child(int sig);
void					ft_sig_usr1(int sig);
void					ft_sig_winch(int sig);

char					*ft_get_path(t_opt *opts);
int						ft_nb_until_next(char *str);

#endif
