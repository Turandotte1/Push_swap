/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:51:27 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/09 05:34:11 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "time.h"

# define OPTIONS "nvc"

# define RED				"\e[31m"
# define BLUE				"\e[34m"
# define CYAN				"\e[36m"
# define BLACK				"\e[30m"
# define GREEN				"\e[32m"
# define BROWN				"\e[0;33m"
# define DEFAULT			"\e[39m"
# define MAGENTA			"\e[35m"
# define BOLD_RED			"\e[1;31m"
# define BOLD_BLUE			"\e[1;34m"
# define BOLD_CYAN			"\e[1;36m"
# define LIGHT_GREY			"\e[37m"
# define BOLD_BLACK			"\e[1;30m"
# define BOLD_GREEN			"\e[1;32m"
# define BOLD_BROWN			"\e[0;1;33m"
# define BOLD_DEFAULT		"\e[1;39m"
# define BOLD_MAGENTA		"\e[1;35m"
# define BOLD_LIGHT_GREY	"\e[1;37m"
# define END				"\033[0m"

/*
**------------Les structures se cachent ici---------------*
*/

typedef struct			s_stack
{
	intmax_t			data;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_args
{
	int					debug;
	int					colors;
	int					num;
	int					total;
	int					print;
	int					checker;
	int					ops;
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
**----------------Les fonctions de l'algo se cachent ici---------------*
*/

void					less_costly_b(t_weight *price_b, int data, t_stack **b);
void					less_costly_a(t_weight *price_a, int position,
																t_stack **a);
void					selection_sort(t_stack **a, t_stack **b, t_args *args);
void					sort_big_stack(t_stack **a, t_stack **b,
																t_args *args);
void					start_rotation(t_weight *price, t_stack **a,
													t_stack **b, t_args *args);

int						compare_data(int current, t_stack **a);

/*
**----------------Les fonctions des operations se cachent ici----------*
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
**-------------------Les fonctions d'affichage se cachent ici----------*
*/

void					debug_opt(t_stack **a, t_stack **b, t_args *args);
void					print_info(t_args *args);
/*
**-------------------Les fonctions de parsing se cachent ici--------------*
*/

int						init_stack_a(t_stack **a, char *av);
int						check_duplicates(t_stack **a);
int						check_args(int ac, char **av, int index);

void					stack_fill(t_stack **head, int data);

/*
**---------------------Les fonctions helpers se cachent ici------------------*
*/

void					check_if_checker_worked(t_stack **a, t_stack **b,
													t_args *args);
void					stack_fill(t_stack **head, int data);
void					free_this_shit(t_stack **head);
void					init_args(t_args *args);

int						check_a(t_stack **a);
int						check_b(t_stack **b);
int						find_min(t_stack **a);
int						check_if_sorted(t_stack **a, t_stack **b);
int						stack_len_calc(t_stack **a);

t_stack					*ft_create_elem(int data);

#endif
