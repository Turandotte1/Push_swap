#include "push_swap.h"

int				notmuchmoves_left_in_a(t_pushswap *push_swap, t_args *args, int *sort)
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
		if (temp != second && NB(first)->nb < NB(tmp)->nb)
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

void		swap_and_sort(t_pushswap *push_swap, t_node *second, t_args *args)
{
	more_effective_moving(push_swap, second, args);
	sa(push_swap);
	if (args->debug == 1)
		debug_opt(push_swap, "sa");
	more_effective_moving(push_swap, find_min(&push_swap->stack_a), args);
}

/*void		more_effective_moving(t_pushswap *push_swap, t_node *node, t_args *args)
{
	int		count;

	count = 0;
	if (reverse_or_notReverse(&l->a, elem, &count) == 0)
	{
		while (count > 0)
		{
			ra(l);
			if (options->v == 1)
				show_piles(l, "ra");
			count--;
		}
	}
	else
	{
		while (1 + count > 0)
		{
			rra(l);
			if (options->v == 1)
				show_piles(l, "rra");
			count--;
		}
	}
}*/