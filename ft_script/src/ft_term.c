/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpillet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 15:25:07 by mpillet           #+#    #+#             */
/*   Updated: 2014/05/03 17:24:07 by mpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <sys/ioctl.h>
#include "ft_script.h"

int						ft_tcgetattr(int fd, struct termios *t)
{
	return (ioctl(fd, TIOCGETA, t));
}

int						ft_tcsetattr(int fd, struct termios *t)
{
	return (ioctl(fd, TIOCSETA, t));
}

void					ft_reset_term(t_opt *opts)
{
	ft_tcsetattr(0, &opts->term);
}

void					ft_raw(t_opt *opts)
{
	struct termios	s;

	ft_tcgetattr(0, &s);
	opts->term = s;
	s.c_lflag &= ~(ICANON | ECHO | ISIG);
	s.c_iflag &= ~(IXON | INLCR | IGNCR | ICRNL);
	s.c_cc[VMIN] = 1;
	s.c_cc[VTIME] = 0;
	ft_tcsetattr(0, &s);
}
