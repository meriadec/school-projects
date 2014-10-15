# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpillet <mpillet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/15 18:48:46 by mpillet           #+#    #+#              #
#*   Updated: 2014/03/04 16:13:02 by bgronon          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME               = libft.a

CC                 = clang
FLAG               = -Wall -Werror -Wextra -pedantic
INCS               = -I ./inc
LIBS               =

SRC                = $(DIR_SRC)/ft_memset.c \
					 $(DIR_SRC)/ft_bzero.c \
					 $(DIR_SRC)/ft_memcpy.c \
					 $(DIR_SRC)/ft_memccpy.c \
					 $(DIR_SRC)/ft_memmove.c \
					 $(DIR_SRC)/ft_memchr.c \
					 $(DIR_SRC)/ft_memcmp.c \
					 $(DIR_SRC)/ft_strlen.c \
					 $(DIR_SRC)/ft_strdup.c \
					 $(DIR_SRC)/ft_strcpy.c \
					 $(DIR_SRC)/ft_strncpy.c \
					 $(DIR_SRC)/ft_strcat.c \
					 $(DIR_SRC)/ft_strncat.c \
					 $(DIR_SRC)/ft_strlcat.c \
					 $(DIR_SRC)/ft_strchr.c \
					 $(DIR_SRC)/ft_strrchr.c \
					 $(DIR_SRC)/ft_strstr.c \
					 $(DIR_SRC)/ft_strnstr.c \
					 $(DIR_SRC)/ft_strcmp.c \
					 $(DIR_SRC)/ft_strncmp.c \
					 $(DIR_SRC)/ft_isalpha.c \
					 $(DIR_SRC)/ft_isdigit.c \
					 $(DIR_SRC)/ft_isalnum.c \
					 $(DIR_SRC)/ft_isascii.c \
					 $(DIR_SRC)/ft_isprint.c \
					 $(DIR_SRC)/ft_toupper.c \
					 $(DIR_SRC)/ft_tolower.c \
					 $(DIR_SRC)/ft_tab_len.c \
					 $(DIR_SRC)/ft_copy_tab.c \
					 $(DIR_SRC)/ft_atoi.c \
					 $(DIR_SRC)/ft_memalloc.c \
					 $(DIR_SRC)/ft_memdel.c \
					 $(DIR_SRC)/ft_strnew.c \
					 $(DIR_SRC)/ft_strdel.c \
					 $(DIR_SRC)/ft_strclr.c \
					 $(DIR_SRC)/ft_striter.c \
					 $(DIR_SRC)/ft_striteri.c \
					 $(DIR_SRC)/ft_strmap.c \
					 $(DIR_SRC)/ft_strmapi.c \
					 $(DIR_SRC)/ft_strequ.c \
					 $(DIR_SRC)/ft_strnequ.c \
					 $(DIR_SRC)/ft_strsub.c \
					 $(DIR_SRC)/ft_strjoin.c \
					 $(DIR_SRC)/ft_isblank.c \
					 $(DIR_SRC)/ft_strtrim.c \
					 $(DIR_SRC)/ft_strsplit.c \
					 $(DIR_SRC)/ft_itoa.c \
					 $(DIR_SRC)/ft_putchar.c \
					 $(DIR_SRC)/ft_putstr.c \
					 $(DIR_SRC)/ft_putendl.c \
					 $(DIR_SRC)/ft_putnbr.c \
					 $(DIR_SRC)/ft_putchar.c \
					 $(DIR_SRC)/ft_putstr_fd.c \
					 $(DIR_SRC)/ft_putchar_fd.c \
					 $(DIR_SRC)/ft_putendl_fd.c \
					 $(DIR_SRC)/ft_putnbr_fd.c \
					 $(DIR_SRC)/ft_lstnew.c \
					 $(DIR_SRC)/ft_dlstnew.c \
					 $(DIR_SRC)/ft_lstdelone.c \
					 $(DIR_SRC)/ft_dlstdelone.c \
					 $(DIR_SRC)/ft_lstdel.c \
					 $(DIR_SRC)/ft_dlstdel.c \
					 $(DIR_SRC)/ft_lstadd.c \
					 $(DIR_SRC)/ft_dlstadd.c \
					 $(DIR_SRC)/ft_lstiter.c \
					 $(DIR_SRC)/ft_lstmap.c \
					 $(DIR_SRC)/ft_lstpush.c \
					 $(DIR_SRC)/ft_dlstpush.c \
					 $(DIR_SRC)/ft_startswith.c \
					 $(DIR_SRC)/ft_charin.c \
					 $(DIR_SRC)/ft_lstswap.c \
					 $(DIR_SRC)/ft_lstsort.c \
					 $(DIR_SRC)/ft_indexof.c \
					 $(DIR_SRC)/ft_printlst.c \
					 $(DIR_SRC)/ft_lstlen.c \
					 $(DIR_SRC)/ft_pad.c \
					 $(DIR_SRC)/get_next_line.c \
					 $(DIR_SRC)/btree_create_node.c \
					 $(DIR_SRC)/btree_insert_data.c \
					 $(DIR_SRC)/btree_print.c \
					 $(DIR_SRC)/ft_free_tab.c \
					 $(DIR_SRC)/ft_multijoin.c \
					 $(DIR_SRC)/ft_struntil.c \
					 $(DIR_SRC)/ft_streplace.c \
					 $(DIR_SRC)/ft_printab.c \
					 $(DIR_SRC)/ft_trunc_tab.c \
					 $(DIR_SRC)/ft_stronly.c \

DIR_SRC            = src
DIR_INC            = inc
DIR_OBJ            = .obj

DIR_LIST           = src

OBJ                = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(DIR_OBJ) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@printf '\e[34m%-51s\e[0m\e[32m[✔]\e[0m\n' "libft.a"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

$(addprefix $(DIR_OBJ)/, %.o) : %.c $(DIR_INC)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(FLAG) -o $@ -c $< $(INCS)
	@printf "\e[32m[✔]\e[0m\n"

clean :
	@if [ -e '$(DIR_OBJ)' ]; then \
		/bin/rm	-fr $(DIR_OBJ); \
		printf "\e[32m[✔]\e[0m project %s cleaned.\n" $(NAME); \
		fi

fclean : clean
	@if [ -e '$(NAME)' ]; then \
		/bin/rm -fr $(NAME); \
		printf "\e[32m[✔]\e[0m project %s fcleaned.\n" $(NAME); \
		fi

re : fclean all

debug : FLAG += -g3 -fno-inline -DD_ERRORS_ON
debug : re
	@printf '\033[1;31m%s\033[0m\n' "Debug enabled."

$(DIR_OBJ) :
	@/bin/mkdir $(DIR_OBJ); \
		for DIR in $(DIR_LIST); \
		do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
		done

.PHONY:	clean fclean re debug
