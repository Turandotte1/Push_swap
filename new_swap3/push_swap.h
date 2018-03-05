#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

# define OPTIONS "nvc"

/*
*------------Les structures se cachent ici---------------*
*/

typedef struct			s_stack
{
	intmax_t			data;
	struct s_stack		*next;
}						t_stack;

typedef struct 			s_args
{
	int 				debug;
	int 				colors;
	int 				num;
	int 				total;
	int 				print;
	int 				checker;
}						t_args;

typedef struct			s_checker
{
	char				*op;
	void				(*ft)(t_stack **a, t_stack **b, t_args *args);
}						t_checker;

typedef struct			s_weight
{
	int					ra;
	int					rb;
	int					rra;
	int					rrb;
	int					total;
}						t_weight;

/*
*----------------Les fonctions de l'algo se cachent ici---------------*
*/

void					less_costly_b(t_weight *price_b, int data, t_stack **b);
void					less_costly_a(t_weight *price_a, int position, t_stack **a);
void					selection_sort(t_stack **a, t_stack **b, t_args *args);
void					sort_big_stack(t_stack **a, t_stack **b, t_args *args);
void					start_rotation(t_weight *price, t_stack **a, t_stack **b, t_args *args);

int						compare_data(int current, t_stack **a);

/*
*----------------Les fonctions des operations se cachent ici----------*
*/

void					pa(t_stack **a, t_stack **b, t_args *args);
void					pb(t_stack **a, t_stack **b, t_args *args);
void					ra(t_stack **a, t_stack **b, t_args *args);
void					rb(t_stack **a, t_stack **b, t_args *args);
void					rr(t_stack **a, t_stack **b, t_args *args);
void					rra(t_stack **a, t_stack **b, t_args *args);
void					rrb(t_stack **a, t_stack **b, t_args *args);
void					rrr(t_stack **a, t_stack **b, t_args *args);
void					sa(t_stack **a, t_stack **b, t_args *args);
void					sb(t_stack **a, t_stack **b, t_args *args);
void					ss(t_stack **a, t_stack **b, t_args *args);

/*
*-------------------Les fonctions d'affichage se cachent ici----------*
*/

void 					debug_opt(t_stack **a, t_stack **b, char *str);

/*
*-------------------Les fonctions helpers se cachent ici--------------*
*/

void					free_this_shit(t_stack **head);
void					init_args(t_args *args);
void					init_checker_tab(t_checker *tab);
void					check_if_worked(t_stack **a, t_stack **b);
void					stack_fill(t_stack **head, int data);

int						find_min(t_stack **a);
int						check_if_sorted(t_stack **a, t_stack **b);
int						check_a(t_stack **a);
int						check_b(t_stack **b);
int						check_duplicates(t_stack **a);
int						check_args(int ac, char **av, int index);
int						stack_len_calc(t_stack **a);

t_stack					*ft_create_elem(int data);

#endif