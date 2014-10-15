/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:12:47 by mpillet           #+#    #+#             */
/*   Updated: 2014/03/09 15:38:44 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include <term.h>
#include "aicu.h"

int					ft_putput(int c)
{
	write(1, &c, 1);
	return (0);
}

int					ft_init_term(void)
{
	char		*term;

	if ((term = (char *) getenv("TERM")) == NULL)
		return (ft_error("Can't determinate terminal"));
	if (tgetent(NULL, term) != 1)
		return (ft_error("Failed with tgetent"));
	return (OK);
}

int					ft_reset_term(void)
{
	struct termios		tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= (ECHO | ICANON | IEXTEN);
	tattr.c_iflag |= (BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	tattr.c_cflag |= (CSIZE | PARENB);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tputs(tgetstr("ei", NULL), 1, ft_putput);
	tputs(tgetstr("ke", NULL), 1, ft_putput);
	tputs(tgetstr("ve", NULL), 1, ft_putput);
	return (OK);
}

void				ft_raw_term(void)
{
	struct termios		tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	tattr.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	tattr.c_cflag &= ~(CSIZE | PARENB);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tputs(tgetstr("ks", NULL), 1, ft_putput);
	tputs(tgetstr("vi", NULL), 1, ft_putput);
}
