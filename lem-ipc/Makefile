# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/12 16:31:16 by mpillet           #+#    #+#              #
#    Updated: 2014/05/29 19:47:20 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LEMIPC					= lemipc
NAME_DRAW					= draw

DIR_LEMIPC					= dir_lem
DIR_DRAW					= dir_draw

all: $(NAME_LEMIPC) $(NAME_DRAW)

$(NAME_LEMIPC): $(DIR_LEMIPC)
	@$(MAKE) -C $(DIR_LEMIPC)
	@/bin/rm -f $(NAME_LEMIPC)
	@/bin/ln -s $(DIR_LEMIPC)/$(NAME_LEMIPC) $(NAME_LEMIPC)

$(NAME_DRAW): $(DIR_DRAW)
	@$(MAKE) -C $(DIR_DRAW)
	@/bin/rm -f $(NAME_DRAW)
	@/bin/ln -s $(DIR_DRAW)/$(NAME_DRAW) $(NAME_DRAW)

clean:
	@$(MAKE) -C $(DIR_LEMIPC) $@
	@$(MAKE) -C $(DIR_DRAW) $@

fclean:
	@$(MAKE) -C $(DIR_LEMIPC) $@
	@$(MAKE) -C $(DIR_DRAW) $@
	@/bin/rm -f $(NAME_LEMIPC)
	@/bin/rm -f $(NAME_DRAW)

debug:
	@$(MAKE) -C $(DIR_LEMIPC) $@
	@$(MAKE) -C $(DIR_DRAW) $@

re: fclean all

.PHONY: clean fclean re $(DIR_LEMIPC) $(DIR_DRAW)
