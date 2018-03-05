NAME1 = checker
NAME2 = push_swap

SRC1 = checker.c verify.c verify_checker.c sorting_helpers.c \
 		operations1.c operations2.c operations3.c options.c \
 		selection_sort.c sort_big_stack.c start_rotation.c \
 		less_costly.c 

SRC2 = push_swap.c verify.c verify_checker.c sorting_helpers.c \
 		operations1.c operations2.c operations3.c options.c \
 		selection_sort.c sort_big_stack.c start_rotation.c \
 		less_costly.c 

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re
	
all: makelibs $(NAME1) $(NAME2)

makelibs:
	@make -C Libft

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) Libft/libft.a -o $(NAME1)
	@echo "Compilation $(NAME1):\033[92m OK\033[0m"

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) Libft/libft.a -o $(NAME2)
	@echo "Compilation $(NAME2):\033[92m OK\033[0m"

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@make -C Libft clean
	@rm -rf $(OBJ1) $(OBJ2)

fclean: clean
	@make -C Libft fclean
	@rm -rf $(NAME1) $(NAME2)
	@echo "\033[0m $(NAME1) $(NAME2) deleted succesfully\033[0m"

re : fclean all