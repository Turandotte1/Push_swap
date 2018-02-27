# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 14:30:06 by mrychkov          #+#    #+#              #
#    Updated: 2018/02/27 12:26:43 by mrychkov         ###   ########.fr        #
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
CC = cc
CFLAGS = -Wall -Wextra -Werror

# files

LIBFT = Libft/

SRC = check.c display.c error.c	init.c list_oper.c 	min_max.c operations1.c	operations2.c operations3.c \
		parsing.c pivot.c precheck_and_selectionsort.c 	push_swap.c quicksort.c sorting_helpers.c 

OBJ = $(SRC:.c=.o)

INC = -I ./Libft/ -L ./Libft -lft

# rules

.PHONY: all clean fclean re

all: $(NAME)

NAME :
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) $(INC)  $(OBJ) -o $@  
	echo "$(OK_COLOR)	--- $(NAME) created! ---	$(NO_COLOR)"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

norme:
	@norminette $(SRC) $(INC)

test:
	@make all -C $(LIBFT)
	@gcc $(CFLAGS) $(INC) $(SRC)
	./a.out 7 4 2 6 3 1 15 

clean:
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ) 2> /dev/null || echo ":(" > /dev/null
	
fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME) 2> /dev/null || echo ":(" > /dev/null
	@echo "$(CLEAN_COLOR)	--- $(NAME)  deleted ---		$(NO_COLOR)"

re: fclean all
