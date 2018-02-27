#include "push_swap.h"

void	init_push_swap(t_pushswap *push_swap)
{
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->stack_op = NULL;
	push_swap->stack_pivot = NULL;
}

void	init_args(t_args *args)
{
	args->info = 0;
	args->num = 0;
	args->debug = 0;
}

void 	double_link_init(t_pushswap *push_swap)
{
	push_swap->stack_a = ft_doublelink_creat();
	push_swap->stack_b = ft_doublelink_creat();
	push_swap->stack_op = ft_doublelink_creat();
	push_swap->stack_pivot = ft_doublelink_creat();
}

void	init_n(t_n *n)
{
	n->nb = 0;
	n->flag = 0;
}

void	init_pivot(t_piv *pivot)
{
	pivot->position = NULL;
	pivot->low = 0;
	pivot->up = 0;
	pivot->distance = 0;
}