# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/29 17:02:59 by mpillet           #+#    #+#              #
#    Updated: 2014/05/03 19:46:45 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= ft_script

DIR_LIBFT			= libft
INC_LIBFT			= libft/inc

CC					= clang
FLAG				= -Wall -Werror -Wextra -pedantic
INCS				= -I inc -I ./inc -I $(INC_LIBFT)
LIBS				= -L $(DIR_LIBFT) -lft

SRC					= $(DIR_SRC)/main.c \
					  $(DIR_SRC)/ft_fill_opts.c \
					  $(DIR_SRC)/ft_errors_opts.c \
					  $(DIR_SRC)/ft_find_shell.c \
					  $(DIR_SRC)/ft_script.c \
					  $(DIR_SRC)/ft_io.c \
					  $(DIR_SRC)/ft_get_opts.c \
					  $(DIR_SRC)/ft_open_file.c \
					  $(DIR_SRC)/ft_shell.c \
					  $(DIR_SRC)/ft_term.c \
					  $(DIR_SRC)/ft_cmd.c \
					  $(DIR_SRC)/ft_find_path.c \
					  $(DIR_SRC)/ft_signal.c \
					  $(DIR_SRC)/ft_sig_child.c \
					  $(DIR_SRC)/ft_sig_usr1.c \
					  $(DIR_SRC)/ft_sig_winch.c \
					  $(DIR_SRC)/ft_end.c \
					  $(DIR_SRC)/tools.c \
					  $(DIR_SRC)/ft_date.c \
					  $(DIR_SRC)/ft_get_master_and_slave.c \

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
	@$(MAKE) -C $(DIR_LIBFT) $@
	@/bin/rm -rf $(DIR_OBJ);
	@printf "\e[32m[✔]\e[0m Project ft_nm cleaned.\n"

fclean: clean
	@$(MAKE) -C $(DIR_LIBFT) $@
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[✔]\e[0m Project ft_nm fcleaned.\n"

re: fclean all

debug : FLAG += -g3 -fno-inline -DD_ERRORS_ON
debug : re
	@printf '\033[1;31m%s\033[0m\n' "Debug enabled."

.PHONY: clean fclean re debug libft
