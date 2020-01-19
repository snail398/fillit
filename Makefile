# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 20:22:48 by lmaximin          #+#    #+#              #
#    Updated: 2020/01/19 16:31:34 by lmaximin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

GC = gcc

FLAG = -Wall -Wextra -Werror

SRC = main.c map.c reader.c shape.c solver.c utils.c

SRC_DIR = ./src

L_FT = libft

OBJ	= $(SRC:.c=.o)	

all: $(NAME)
	
$(NAME):
		@$(MAKE) -C $(L_FT)
		$(GC) $(FLAG) $(addprefix $(SRC_DIR)/, $(SRC)) -c 
		$(GC) $(FLAG) -o $(NAME) $(OBJ) -L libft -lft
	
clean:
		rm -rf $(OBJ)
		@$(MAKE) clean -C $(L_FT)

fclean: clean
		/bin/rm -f $(NAME)
		@$(MAKE) fclean -C $(L_FT)

re: fclean all

.PHONY: all clean fclean re

