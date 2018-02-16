# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:30:06 by mrychkov          #+#    #+#              #
#    Updated: 2018/02/16 17:23:45 by mrychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colours

NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

# compiliation

NAME = push_swap
# NAME2 = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# files

SRC = 	push_swap.c \
		parsing.c \
		stack_helpers.c \
		stack_operations.c \
		pivot_found.c \
		sorting.c \
		sorting_helpers.c \

OBJ = $(SRC:.c=.o)
INC = -I ./libft/ -L ./libft -lft

# rules

.PHONY: all clean fclean re

all: $(NAME)
	@make all -C libft
	@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $@ 
	@echo "$(OK_COLOR)	--- $(NAME) created! ---	$(NO_COLOR)"

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)

norme:
	@norminette $(SRC) $(INC)

test:
	@make all -C libft
	@gcc $(CFLAGS) $(INC) $(SRC)

clean:
	@rm -rf $(OBJ)
	@make clean -C libft
	
fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "$(CLEAN_COLOR)	--- $(NAME)  deleted ---		$(NO_COLOR)"

re: fclean all
