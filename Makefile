# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 20:22:48 by lmaximin          #+#    #+#              #
#    Updated: 2020/01/12 11:11:33 by lmaximin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

GC = gcc

FLAG = -Wall -Wextra -Werror

SRC = main.c map.c reader.c shape.c solver.c utils.c

SRC_DIR = ./src

L_FT = libft

OBJ	= $(SRC:.c=.o)	

all: 
	@$(MAKE) -C $(L_FT)
	$(GC) $(FLAG) $(addprefix $(SRC_DIR)/, $(SRC)) -c 
	$(GC) $(FLAG) -o $(NAME) $(OBJ) -L libft -lft


clean:
		rm -rf $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

