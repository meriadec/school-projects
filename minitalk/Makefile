# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 17:58:07 by mpillet           #+#    #+#              #
#    Updated: 2014/02/09 16:13:48 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME               = minitalk

CLIENT_DIR         = client_dir
SERVER_DIR         = server_dir

NAME_CLIENT        = client
NAME_SERVER        = serveur

DIR_LIBFT          = libft

all: $(NAME)

$(NAME): $(DIR_LIBFT) $(NAME_CLIENT) $(NAME_SERVER)
	@/bin/rm -rf $(NAME_CLIENT)
	@/bin/rm -rf $(NAME_SERVER)
	@/bin/ln -s $(CLIENT_DIR)/$(NAME_CLIENT) .
	@echo ""
	@printf "\e[32m[✔]\e[0m \e[35m./client\e[0m is available\n"
	@/bin/ln -s $(SERVER_DIR)/$(NAME_SERVER) .
	@printf "\e[32m[✔]\e[0m\e[0m \e[35m./serveur\e[0m is available\n"
	@echo ""

libft:
	$(MAKE) -C $(DIR_LIBFT)

$(NAME_CLIENT):
	$(MAKE) -C $(CLIENT_DIR)

$(NAME_SERVER):
	$(MAKE) -C $(SERVER_DIR)

clean:
	$(MAKE) -C libft $@
	$(MAKE) -C $(CLIENT_DIR) $@
	$(MAKE) -C $(SERVER_DIR) $@

fclean: clean
	$(MAKE) -C libft $@
	$(MAKE) -C $(CLIENT_DIR) $@
	$(MAKE) -C $(SERVER_DIR) $@
	/bin/rm -rf $(NAME_CLIENT)
	/bin/rm -rf $(NAME_SERVER)

re: fclean all

.PHONY: clean fclean re libft client serveur
