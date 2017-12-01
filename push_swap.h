#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct 			s_stack
{
    int					data;
    struct s_stack 		*next;
}						t_stack;

typedef struct 			s_args
{
	int 				options:1;
	int 				stat:1;
	int 				debug:1;
	int 				size;
	int 				final_size;
	int 				push;
	int 				rot;
	int 				pivot;
	int 				temp;
}						t_args;

void					error_managment(int key, intmax_t i, char *str);
void					print_out(t_list *instruct, t_stack **a);
void					free_everything(t_stack *a, t_stack *b, t_args *info, t_list *instruct);
void 					free_stack(t_stack *s);
void					s_pop(t_stack **top);
void					sort_this_shit(t_stack **a, t_stack **b, t_args *info, t_list **instruct);
void 					presort(t_stack **a, t_stack **b, t_args *info, t_list **instruct);
void 					backwards_sort(t_stack **a, t_stack **b, t_args *info, t_list **instruct);
void 					back_presort(t_stack **a, t_stack **b, t_args *info, t_list **instruct);
void					small_len(t_stack **a, t_stack **b, t_list **instruct);
void					stock_instruct(t_list **instruct, char *str);
void					print_final_stack(t_stack **a);

int						get_user_data(int ac, char **av, t_stack **stack_a, t_args *info);
int						is_sorted_up(t_stack **stack);
int						is_sorted_down(t_stack **stack);
int 					stack_len(t_stack **stack);
int						pivot_found(t_stack *a, int size);
int						s_push(t_stack **dest, t_stack **src);
int						s_swap(t_stack *stack);
int						s_rotate(t_stack **stack);
int						s_reverse_rotate(t_stack **stack);
int 					backwards_sorts_calc(t_stack **a, int pivot, int size);
int						sorts_calc(t_stack **a, int pivot, int size);
int						ft_push(t_stack **top, int data);

t_stack					*create_link(int data);

#endif