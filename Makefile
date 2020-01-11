# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 20:22:48 by lmaximin          #+#    #+#              #
#    Updated: 2020/01/11 11:02:16 by lmaximin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = work

GC = gcc

FLAG = -Wall -Wextra -Werror

FOLD = src/

SRC = $(FOLD)main.c $(FOLD)map.c $(FOLD)reader.c $(FOLD)shape.c $(FOLD)solver.c $(FOLD)utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME):
	$(GC) $(FLAG) -o $(NAME) $(SRC) -L libft -lft

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

