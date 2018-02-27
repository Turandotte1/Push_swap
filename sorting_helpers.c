#include "push_swap.h"

int				is_sorted(t_double *stack_a)
{
	t_node		*temp;

	temp = stack_a->head;
	while (temp)
	{
		if (temp->next != NULL && NB(temp)->nb < NB(temp->next)->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int				is_reversed(t_double *stack_a)
{
	t_node		*temp;

	temp = stack_a->head;
	while (temp)
	{
		if (temp->next != NULL && NB(temp)->nb > NB(temp->next)->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int				sort_small_stack(t_pushswap *push_swap, t_args *args, int *sort)
{
	int			count;
	t_node		*temp;

	count = 0;
	temp = (push_swap->stack_a)->head;
	while (temp)
	{
		if (temp->next != NULL && NB(temp)->nb > NB(temp->next)->nb)
			count++;
		if (count > 0)
			return (0);
		temp = temp->next;
	}
	sa_op(push_swap);
	if (args->debug == 1)
		debug_opt(push_swap, "sa");
	rra_op(push_swap);
	if (args->debug == 1)
		debug_opt(push_swap, "rra");
	*sort = 1;
	return (1);
}

void			less_costly(t_pushswap *push_swap, t_node *node, t_args *args)
{
	int		count;

	count = 0;
	if (reverse_or_rotate(&push_swap->stack_a, node, &count) == 0)
	{
		while (count > 0)
		{
			ra_op(push_swap);
			if (args->debug == 1)
				debug_opt(push_swap, "ra");
			count--;
		}
	}
	else
	{
		while (1 + count > 0)
		{
			rra_op(push_swap);
			if (args->debug == 1)
				debug_opt(push_swap, "rra");
			count--;
		}
	}
}

int				reverse_or_rotate(t_double **stack, t_node *node, int *count)
{
	int			count_head;
	int			count_tail;
	t_node		*temp_b;
	t_node		*temp_e;

	temp_b = (*stack)->head;
	temp_e = (*stack)->tail;
	count_head = 0;
	count_tail = 0;
	while (temp_b && temp_b != node)
	{
		count_head++;
		temp_b = temp_b->next;
	}
	count_tail = (*stack)->length - 1 - count_head;
	if (count_head >= count_tail)
		*count = count_tail;
	else
		*count = count_head;
	return ((count_head >= count_tail) ? 0 : 1);
}