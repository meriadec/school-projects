# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/08 12:16:02 by mpillet           #+#    #+#              #
#    Updated: 2014/03/09 18:33:48 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= puissance4

CC					= clang
FLAG				= -Wall -Werror -Wextra -pedantic
INCS				= -I inc -I ./inc -I libft/inc
LIBS				= -L libft -lft -L /usr/lib -lncurses -ltermcap

SRC					= $(DIR_SRC)/main.c \
					  $(DIR_SRC)/terminal.c \
					  $(DIR_SRC)/ft_error.c \
					  $(DIR_SRC)/ft_launch.c \
					  $(DIR_SRC)/ft_ascii.c \
					  $(DIR_SRC)/ft_print_foots.c \
					  $(DIR_SRC)/ft_get_ctx.c \
					  $(DIR_SRC)/ft_malloc_grid.c \
					  $(DIR_SRC)/ft_del_grid.c \
					  $(DIR_SRC)/ft_print_grid.c \
					  $(DIR_SRC)/ft_loop.c \
					  $(DIR_SRC)/ft_stop.c \
					  $(DIR_SRC)/ft_player_play.c \
					  $(DIR_SRC)/ft_ia_play.c \
					  $(DIR_SRC)/ft_play_on.c \
					  $(DIR_SRC)/ft_unplay_on.c \
					  $(DIR_SRC)/ft_play.c \
					  $(DIR_SRC)/ft_unplay.c \
					  $(DIR_SRC)/ft_win.c \
					  $(DIR_SRC)/ft_check.c \
					  $(DIR_SRC)/ft_move_new.c \
					  $(DIR_SRC)/ft_dup_grid.c \
					  $(DIR_SRC)/ft_minmax.c \
					  $(DIR_SRC)/ft_get_score.c \
					  $(DIR_SRC)/ft_neighbours.c \
					  $(DIR_SRC)/ft_annoy.c \
					  $(DIR_SRC)/ft_is_empty.c \
					  $(DIR_SRC)/ft_useless.c \
					  $(DIR_SRC)/ft_center.c \
					  $(DIR_SRC)/ft_is_victorious.c \
					  $(DIR_SRC)/ft_notif.c \
					  $(DIR_SRC)/ft_aff_arrow.c \
					  $(DIR_SRC)/ft_treat_key.c \
					  $(DIR_SRC)/treat_key_enter.c \
					  $(DIR_SRC)/treat_key_right.c \
					  $(DIR_SRC)/treat_key_left.c \
					  $(DIR_SRC)/ft_check_size.c \
					  $(DIR_SRC)/ft_get_fd.c \

# ---------------------------------------------------------------------------- #

DIR_LIST			= src
DIR_SRC				= src
DIR_INC				= inc
DIR_OBJ				= .obj

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# ---------------------------------------------------------------------------- #

all: libft $(NAME)

libft:
	@$(MAKE) -C libft

$(addprefix $(DIR_OBJ)/, %.o): %.c $(DIR_INC)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(FLAG) $(INCS) -o $@ -c $<
	@printf "\e[32m[✔]\e[0m\n"

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

$(DIR_OBJ) :
	@/bin/mkdir $(DIR_OBJ); \
		for DIR in $(DIR_LIST); \
		do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
		done

clean:
	@$(MAKE) -C libft $@
	@/bin/rm -rf $(DIR_OBJ);
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

debug : FLAG += -g3 -fno-inline -DD_ERRORS_ON
debug : re
	@printf '\033[1;31m%s\033[0m\n' "Debug enabled."

.PHONY: clean fclean re debug libft
