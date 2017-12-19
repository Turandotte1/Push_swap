NAME = push_swap

H_DIR = includes/
C_DIR = srcs/
O_DIR = obj/
LIBFTPRINTF = libftprintf/

FLAGS = -Wall -Wextra -Werror
LINKS = -I$(H_DIR) -I$(LIBFTPRINTF)

C_FILES = $(shell ls -1 $(C_DIR) | grep "\.c")

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

all:
	@make -C $(LIBFTPRINTF)
	@make $(NAME)

$(NAME): $(O_FILES)
	$(eval FT_O = $(shell find $(LIBFTPRINTF) -type f -print | grep "\.o"))
	gcc -o $(NAME) $(O_FILES) -L ./libftprintf/ -lftprintf

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@rmdir -p $(O_DIR) 2> /dev/null || echo "" > /dev/null
	@make -C $(LIBFTPRINTF) clean

fclean: clean
	@rm -rf $(NAME) 2> /dev/null || echo "" > /dev/null
	@make -C $(LIBFTPRINTF) fclean

re: fclean all

.PHONY: all clean fclean re