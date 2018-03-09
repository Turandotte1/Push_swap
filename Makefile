# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 01:21:50 by mrychkov          #+#    #+#              #
#    Updated: 2018/03/09 03:54:52 by mrychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

NAME1 = checker
NAME2 = push_swap

SRC1 = checker.c init.c less_costly.c operations1.c operations2.c operations3.c \
options.c selection_sort.c sort_big_stack.c sorting_helpers.c start_rotation.c \
verif_args.c verif_sort.c  

SRC2 = push_swap.c init.c less_costly.c operations1.c operations2.c operations3.c \
options.c selection_sort.c sort_big_stack.c sorting_helpers.c start_rotation.c \
verif_args.c verif_sort.c 

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re
	
all: makelibs $(NAME1) $(NAME2)

makelibs:
	@make -C Libft

$(NAME1): $(OBJ1)
	@$(CC)  -g3 $(CFLAGS) $(OBJ1) Libft/libft.a -o $(NAME1)
	@echo "$(CLEAN_COLOR)Compilation $(NAME1): $(OK_COLOR)OK $(NO_COLOR)"

$(NAME2): $(OBJ2)
	@$(CC)  -g3 $(CFLAGS) $(OBJ2) Libft/libft.a -o $(NAME2)
	@echo "$(CLEAN_COLOR)Compilation $(NAME2): $(OK_COLOR)OK $(NO_COLOR)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@make -C Libft clean
	@rm -rf $(OBJ1) $(OBJ2)

fclean: clean
	@make -C Libft fclean
	@rm -rf $(NAME1) $(NAME2)
	@echo "$(CLEAN_COLOR)Cleaning $(NAME1) and $(NAME2): $(OK_COLOR)OK $(NO_COLOR)"

re : fclean all
