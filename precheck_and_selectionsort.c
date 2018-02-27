#include "push_swap.h"

int				notmuchmoves_left_in_a(t_pushswap *push_swap, 
									t_args *args, int *sort)
{
	int			count;
	t_node		*temp;
	t_node		*first;
	t_node		*second;

	count = 0;
	temp = (push_swap->stack_a)->head;
	first = NULL;
	second = NULL;
	while (temp)
	{
		if (temp->next != NULL && NB(temp)->nb < NB(temp->next)->nb)
		{
			first = temp;
			second = temp->next;
			count++;
		}
		temp = temp->next;
	}
	if (count != 1 || !(check_second(first, second))
		|| !(check_first(first, second)))
		return (0);
	swap_and_sort(push_swap, second, args);
	*sort = 4;
	return (1);
}

int			check_second(t_node *first, t_node *second)
{
	t_node	*temp;

	temp = NULL;
	if (second->next)
		temp = second->next;
	else
		return (1);
	while (temp)
	{
		if (temp != second && NB(first)->nb < NB(temp)->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			check_first(t_node *first, t_node *second)
{
	t_node	*temp;

	temp = NULL;
	if (first->prev)
		temp = first->prev;
	else
		return (1);
	while (temp)
	{
		if (temp != second && NB(first)->nb > NB(temp)->nb)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

void			swap_and_sort(t_pushswap *push_swap, t_node *second, t_args *args)
{
	less_costly(push_swap, second, args);
	sa_op(push_swap);
	if (args->debug == 1)
		debug_opt(push_swap, "sa");
	less_costly(push_swap, find_min(&push_swap->stack_a), args);
}

void			selection_sort(t_pushswap *push_swap, t_args *args, int *sort)
{
	while ((push_swap->stack_a)->length > 0)
	{
		less_costly(push_swap, find_min(&push_swap->stack_a), args);
		pb_op(push_swap);
		if (args->debug == 1)
			debug_opt(push_swap, "pb");
	}
	while ((push_swap->stack_b)->length > 0)
	{
		pa_op(push_swap);
		if (args->debug == 1)
			debug_opt(push_swap, "pa");
	}
	*sort = 2;
}