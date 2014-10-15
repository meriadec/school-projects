# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 16:19:08 by mpillet           #+#    #+#              #
#    Updated: 2014/02/09 16:19:10 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME               = serveur

CC                 = clang
FLAG               = -Wall -Werror -Wextra -pedantic
INCS               = -I $(DIR_INC) -I ../libft/inc
LIBS               = -L ../libft -lft

SRC                = $(DIR_SRC)/server.c \
					 $(DIR_SRC)/ft_error.c \
					 $(DIR_SRC)/ft_realloc.c \
					 $(DIR_SRC)/ft_get_input.c \
					 $(DIR_SRC)/ft_aff_pid.c \
					 $(DIR_SRC)/ft_output.c \
					 $(DIR_SRC)/ft_fill_char.c \
					 $(DIR_SRC)/ft_read_input.c \

DIR_SRC            = src
DIR_INC            = ../inc
DIR_OBJ            = .obj

DIR_LIST           = src

OBJ                = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

all: $(NAME)

$(addprefix $(DIR_OBJ)/, %.o): %.c $(DIR_INC)
	$(CC) $(FLAG) $(INCS) -o $@ -c $<

$(NAME): $(DIR_OBJ) $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)

$(DIR_OBJ) :
	@/bin/mkdir $(DIR_OBJ); \
		for DIR in $(DIR_LIST); \
		do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
		done

clean:
	/bin/rm -rf $(DIR_OBJ);

fclean: clean
	/bin/rm -rf $(NAME);

re: fclean all

.PHONY: clean fclean re
