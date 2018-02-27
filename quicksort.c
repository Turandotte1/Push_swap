#include "push_swap.h"

void			quicksort_in_your_face(t_pushswap *push_swap, t_args *args, int *sort)
{
	int			piv;

	(void)args;
	piv = define_pivot(push_swap);
	stack_divide(push_swap, piv, args);
	if (!(is_sorted(push_swap->stack_a)))
		sort_a(push_swap, args);
	if (!(is_reversed(push_swap->stack_b)))
		sort_b(push_swap, args);
	while (push_swap->stack_b->length > 0)
		pa_op(push_swap);
		if (args->debug == 1)
			debug_opt(push_swap, "pa");
	*sort = 3;
}

void			stack_divide(t_pushswap *push_swap, int piv, t_args *args)
{
	int			count;
	t_node		*temp;

	(void)piv;
	(void)args;
	count = (push_swap->stack_a)->length;
	temp = (push_swap->stack_a)->tail;
	while (count > 0)
	{
		if (NB(temp)->nb < piv)
			pb_op(push_swap);
		else
			ra_op(push_swap);
		count--;
		temp = (push_swap->stack_a)->tail;
	}
}

void			sort_a(t_pushswap *push_swap, t_args *args)
{
	int			count;

	count = 0;
	while ((push_swap->stack_a)->length > 0)
	{
		less_costly(push_swap, find_min(&push_swap->stack_a), args);
		pb_op(push_swap);
		count++;
		if (args->debug == 1)
			debug_opt(push_swap, "pb");
	}
	while (count > 0)
	{
		pa_op(push_swap);
		if (args->debug == 1)
			debug_opt(push_swap, "pa");
		count--;
	}
}

void			sort_b(t_pushswap *push_swap, t_args *args)
{
	int			count;

	count = 0;
	while ((push_swap->stack_b)->length > 0)
	{
		less_costly_b(push_swap, find_max(&push_swap->stack_b), args);
		pa_op(push_swap);
		count++;
		if (args->debug == 1)
			debug_opt(push_swap, "pa");
	}
	while (count > 0)
	{
		pb_op(push_swap);
		if (args->debug == 1)
			debug_opt(push_swap, "pb");
		count--;
	}
}

void			less_costly_b(t_pushswap *push_swap, t_node *node, t_args *args)
{
	int			count;

	count = 0;
	if (reverse_or_rotate(&push_swap->stack_b, node, &count) == 0)
	{
		while (count > 0)
		{
			rb_op(push_swap);
			if (args->debug == 1)
				debug_opt(push_swap, "rb");
			count--;
		}
	}
	else
	{
		count++;
		while (count > 0)
		{
			rrb_op(push_swap);
			if (args->debug == 1)
				debug_opt(push_swap, "rrb");
			count--;
		}
	}
}
