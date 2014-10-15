# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/12 16:31:16 by mpillet           #+#    #+#              #
#    Updated: 2014/05/18 17:21:04 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT					= client
NAME_SERVER					= server

DIR_CLIENT					= dir_client
DIR_SERVER					= dir_server

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):
	@$(MAKE) -C $(DIR_CLIENT)
	@/bin/rm -f $(NAME_CLIENT)
	@/bin/ln -s $(DIR_CLIENT)/$(NAME_CLIENT) .

$(NAME_SERVER):
	@$(MAKE) -C $(DIR_SERVER)
	@/bin/rm -f $(NAME_SERVER)
	@/bin/ln -s $(DIR_SERVER)/$(NAME_SERVER) .

clean:
	@$(MAKE) -C $(DIR_CLIENT) $@
	@$(MAKE) -C $(DIR_SERVER) $@

fclean:
	@$(MAKE) -C $(DIR_CLIENT) $@
	@$(MAKE) -C $(DIR_SERVER) $@
	@/bin/rm -f $(NAME_CLIENT)
	@/bin/rm -f $(NAME_SERVER)

re: fclean all
