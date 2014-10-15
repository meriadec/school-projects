/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:12:47 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/10 18:32:05 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include <term.h>
#include "philo.h"

int						ft_putput(int c)
{
	write(1, &c, 1);
	return (0);
}

void					ft_init_term(void)
{
	char				*term;

	if ((term = (char *)getenv("TERM")) == NULL)
		ft_error("Can't determinate terminal");
	if (tgetent(NULL, term) != 1)
		ft_error("Failed with tgetent");
}

int						ft_reset_term(void)
{
	struct termios		tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON | IEXTEN);
	tattr.c_iflag |= (BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	tattr.c_cflag |= (CSIZE | PARENB);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tputs(tgetstr("te", NULL), 1, ft_putput);
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(tgetstr("ke", NULL), 1, ft_putput);
	tputs(tgetstr("ve", NULL), 1, ft_putput);
	return (OK);
}

void					ft_raw_term(void)
{
	struct termios		tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	tattr.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	tattr.c_cflag &= ~(CSIZE | PARENB);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tputs(tgetstr("ti", NULL), 1, ft_putput);
	tputs(tgetstr("ks", NULL), 1, ft_putput);
	tputs(tgetstr("vi", NULL), 1, ft_putput);
}
