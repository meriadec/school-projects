# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 16:19:22 by mpillet           #+#    #+#              #
#    Updated: 2014/02/09 17:39:37 by mpillet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME               = client

CC                 = clang
FLAG               = -Wall -Werror -Wextra -pedantic
INCS               = -I $(DIR_INC) -I ../libft/inc
LIBS               = -L ../libft -lft

SRC                = $(DIR_SRC)/client.c \
					 $(DIR_SRC)/ft_err_timeout.c \

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
