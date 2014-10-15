# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/29 17:02:59 by mpillet           #+#    #+#              #
#    Updated: 2014/05/31 12:08:37 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= lemipc

DIR_LIBFT			= ../libft
INC_LIBFT			= ../libft/inc
INC_SHARED			= ../inc

CC					= clang
FLAG				= -Wall -Werror -Wextra -pedantic
INCS				= -I $(DIR_INC) -I $(INC_LIBFT) -I $(INC_SHARED)
LIBS				= -L $(DIR_LIBFT) -lft

SRC					= $(DIR_SRC)/main.c \
					  $(DIR_SRC)/errors.c \
					  $(DIR_SRC)/ft_usage.c \
					  $(DIR_SRC)/ft_ctx.c \
					  $(DIR_SRC)/ft_set_params.c \
					  $(DIR_SRC)/ft_get_shared_mem.c \
					  $(DIR_SRC)/ft_create_shared_mem.c \
					  $(DIR_SRC)/ft_get_key.c \
					  $(DIR_SRC)/ft_wait_q.c \
					  $(DIR_SRC)/ft_print_map.c \
					  $(DIR_SRC)/ft_place.c \
					  $(DIR_SRC)/ft_move_left.c \
					  $(DIR_SRC)/ft_move_right.c \
					  $(DIR_SRC)/ft_move_down.c \
					  $(DIR_SRC)/ft_move_up.c \
					  $(DIR_SRC)/ft_open_shared.c \
					  $(DIR_SRC)/ft_close_shared.c \
					  $(DIR_SRC)/ft_liberate.c \
					  $(DIR_SRC)/ft_create_semaphores.c \
					  $(DIR_SRC)/ft_play.c \
					  $(DIR_SRC)/ft_is_dead.c \
					  $(DIR_SRC)/sem_read_start.c \
					  $(DIR_SRC)/sem_read_end.c \
					  $(DIR_SRC)/sem_write_start.c \
					  $(DIR_SRC)/sem_write_end.c \

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
