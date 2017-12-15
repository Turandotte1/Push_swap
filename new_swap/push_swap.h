#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define SWAP_A			"sa"
# define SWAP_B			"sb"
# define SWAP_SWAP		"ss"
# define PUSH_A			"pa"
# define PUSH_B			"pb"
# define ROT_A			"ra"
# define ROT_B			"rb"
# define ROT_ROT		"rr"
# define REVROT_A		"rra"
# define REVROT_B		"rrb"
# define REVROT_REVROT	"rrr"

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_sort
{
	int 			rot;
	int 			push;
	int 			len;
	int 			tmp_len;
	int				big_len;	
	int 			pivot;
}					t_sort;

typedef struct		s_args
{
	bool			stack_refresh;
	bool			display_commands;
	bool			clear_screen;
	bool			selection_sort;
	bool			quick_sort;
}					t_args;

typedef struct		s_ptr_func
{
	int				(*ptr)(t_stack **, t_stack **, char *);
	char			*key;
}					t_ptr_func;

#endif