#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

# define NB(X)				((t_n *)((X)->content))
# define ACTIONS(X)			((t_act *)((X)->content))
# define PIVOT(X)			((t_piv *)((X)->content))
# define OPTIONS			"nvi"

/* 
**------------ Les structures se cachent ici ------------
*/

typedef struct 			s_pushswap
{
  t_double				*stack_a;
  t_double 				*stack_b;
  t_double				*stack_op;
  t_double				*stack_pivot;  
}						t_pushswap;

typedef struct 			s_args
{
	int					info:1;
	int 				num:1;
	int 				debug:1;
}						t_args;

typedef struct 			s_n
{
	int					nb;
	int					flag;	
}						t_n;

typedef struct			s_piv
{
	t_node				*position;
	int					low;
	int					up;
	int					distance;
}						t_piv;

typedef struct			s_act
{
	char				*name;
}						t_act;

/*
**-----------Les prototypes se cachent ici --------
*/

int 					check_digit(char *str);
int						opt_browse(char *str, t_args *args);
int						check_length(char *str);
int						check_duplicates(t_double **stack_a);
int						find_n(int nb, t_double *stack_a);
int 					input_check(char **av, t_double **a, t_args *args);
int						get_user_data(char **av, t_pushswap *push_swap, t_args *args);
int						define_pivot(t_pushswap *push_swap);
int						which_pivot(t_pushswap *push_swap, int value);
int						notmuchmoves_left_in_a(t_pushswap *push_swap, t_args *args, int *sort);
int						check_second(t_node *first, t_node *second);
int						check_first(t_node *first, t_node *second);
int						is_sorted(t_double *stack_a);
int						is_reversed(t_double *stack_a);
int						sort_small_stack(t_pushswap *push_swap, t_args *args, int *sort);
int						reverse_or_rotate(t_double **stack, t_node *node, int *count);

void					save_args(char args, t_args *as);
void					print_it_out(t_pushswap *push_swap, t_args *args, int sort);
void					print_operations(t_double *op);
void					which_sort(int sort);
void					debug_opt(t_pushswap *push_swap, char *op);
void					stack_print(t_double *stack);
void					push_swap_error(int key, intmax_t i, char *str);
void					init_push_swap(t_pushswap *push_swap);
void					init_args(t_args *args);
void 					double_link_init(t_pushswap *push_swap);
void					init_n(t_n *n);
void					init_pivot(t_piv *pivot);
void					delete_ops(t_double **stack);
void					free_ops(t_double **stack, t_node *to_remove);
void					sa_op(t_pushswap *push_swap);
void					sb_op(t_pushswap *push_swap);
void					ss_op(t_pushswap *push_swap);
void					pa_src(t_double *stack);
void					pa_dst(t_double *stack, t_node *push);
void					pa_op(t_pushswap *push_swap);
void					pb_op(t_pushswap *push_swap);
void					ra_op(t_pushswap *push_swap);
void					rb_op(t_pushswap *push_swap);
void					rr_op(t_pushswap *push_swap);
void					rra_op(t_pushswap *push_swap);
void					rrb_op(t_pushswap *push_swap);
void					rrr_op(t_pushswap *push_swap);
void					save_num(char **av, t_double **a, t_n *n, int i);
void					define_pivot_fuck_the_norm(t_pushswap *push_swap);
void					pivot_up(t_pushswap *push_swap, t_piv *pivot);
void					pivot_distance(t_piv *pivot);
void					swap_and_sort(t_pushswap *push_swap, t_node *second, t_args *args);
void					selection_sort(t_pushswap *push_swap, t_args *args, int *sort);
void					sort_this_shit(t_pushswap *push_swap, t_args *args);
void					quicksort_in_your_face(t_pushswap *push_swap, t_args *args, int *sort);
void					stack_divide(t_pushswap *push_swap, int piv, t_args *args);
void					sort_a(t_pushswap *push_swap, t_args *args);
void					sort_b(t_pushswap *push_swap, t_args *args);
void					less_costly_b(t_pushswap *push_swap, t_node *node, t_args *args);
void					less_costly(t_pushswap *push_swap, t_node *node, t_args *args);

t_node					*find_min(t_double **stack);
t_node					*find_max(t_double **stack);

#endif