#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2014/04/21 14:32:40 by mpillet           #+#    #+#             *#
#*   Updated: 2014/04/21 14:42:37 by mpillet          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME				= build

NAME_FT_NM			= ft_nm
NAME_FT_OTOOL		= ft_otool

DIR_FT_NM			= dir_nm
DIR_FT_OTOOL		= dir_otool

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(DIR_FT_NM)
	@$(MAKE) -C $(DIR_FT_OTOOL)
	@/bin/rm -rf $(NAME_FT_NM)
	@/bin/rm -rf $(NAME_FT_OTOOL)
	@/bin/ln -s $(DIR_FT_NM)/$(NAME_FT_NM) .
	@/bin/ln -s $(DIR_FT_OTOOL)/$(NAME_FT_OTOOL) .

clean:
	@$(MAKE) -C $(DIR_FT_NM) $@
	@$(MAKE) -C $(DIR_FT_OTOOL) $@

fclean:
	@$(MAKE) -C $(DIR_FT_NM) $@
	@$(MAKE) -C $(DIR_FT_OTOOL) $@
	@/bin/rm -rf $(NAME_FT_NM)
	@/bin/rm -rf $(NAME_FT_OTOOL)

re: fclean all
