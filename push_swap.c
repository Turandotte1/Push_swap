#include "push_swap.h"

void			sort_this_shit(t_pushswap *push_swap, t_args *args)
{
	int			sort;

	sort = 0;
	if (push_swap->stack_a->length > 1)
	{
		while (!(is_sorted(push_swap->stack_a)))
		{
			if ((push_swap->stack_a)->length <= 19)
			{
				if ((push_swap->stack_a)->length == 3 
						&& is_reversed(push_swap->stack_a) == 1)
				{
					sort_small_stack(push_swap, args, &sort);
				}
				else if (!(notmuchmoves_left_in_a(push_swap, args, &sort)))
					selection_sort(push_swap, args, &sort);
			}
			else if (!(notmuchmoves_left_in_a(push_swap, args, &sort)))
				quicksort_in_your_face(push_swap, args, &sort);
		}
	}
	if (push_swap->stack_a->length != 0)
		print_it_out(push_swap, args, sort);
}

int				main(int ac, char **av)
{
	t_pushswap	push_swap;
	t_args		args;

	init_push_swap(&push_swap);
	init_args(&args);
	if (ac > 1)
	{
		double_link_init(&push_swap);
		get_user_data(av, &push_swap, &args);
		sort_this_shit(&push_swap, &args);
	}
	else
		return (-1);
	return (0);
}
