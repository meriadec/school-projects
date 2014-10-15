# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/29 17:02:59 by mpillet           #+#    #+#              #
#    Updated: 2014/05/18 15:46:22 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= client

DIR_LIBFT			= ../libft
INC_LIBFT			= ../libft/inc

CC					= clang
FLAG				= -Wall -Werror -Wextra -pedantic
INCS				= -I $(DIR_INC) -I $(INC_LIBFT)
LIBS				= -L $(DIR_LIBFT) -lft

SRC					= $(DIR_SRC)/main.c \
					  $(DIR_SRC)/ft_usage.c \
					  $(DIR_SRC)/ft_ctx.c \
					  $(DIR_SRC)/ft_clear.c \
					  $(DIR_SRC)/ft_error.c \
					  $(DIR_SRC)/ft_success.c \
					  $(DIR_SRC)/ft_read.c \
					  $(DIR_SRC)/ft_create_client.c \
					  $(DIR_SRC)/ft_is_valid.c \
					  $(DIR_SRC)/ft_is_cd.c \
					  $(DIR_SRC)/ft_prompt.c \

# ---------------------------------------------------------------------------- #

DIR_LIST			= src
DIR_SRC				= src
DIR_INC				= inc
DIR_OBJ				= .obj

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# ---------------------------------------------------------------------------- #

all: libft $(NAME)

libft:
	@$(MAKE) -C $(DIR_LIBFT)

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

$(addprefix $(DIR_OBJ)/, %.o): %.c $(DIR_INC)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(FLAG) $(INCS) -o $@ -c $<
	@printf "\e[32m[✔]\e[0m\n"

clean:
	@$(MAKE) -C $(DIR_LIBFT) $@
	@/bin/rm -rf $(DIR_OBJ);
	@printf "\e[32m[✔]\e[0m Project $(NAME) cleaned.\n"

fclean: clean
	@$(MAKE) -C $(DIR_LIBFT) $@
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[✔]\e[0m Project $(NAME) fcleaned.\n"

re: fclean all

debug: FLAG += -g3 -fno-inline -DD_ERRORS_ON
debug: re
	@printf '\033[1;31m%s\033[0m\n' "Debug enabled."

$(DIR_OBJ):
	@/bin/mkdir $(DIR_OBJ); \
		for DIR in $(DIR_LIST); \
		do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
		done

.PHONY: clean fclean re debug libft
