#include "push_swap.h"

int				define_pivot(t_pushswap *push_swap)
{
	define_pivot_fuck_the_norm(push_swap);
	return (which_pivot(push_swap, 1));
}

void			define_pivot_fuck_the_norm(t_pushswap *push_swap)
{
	int			count;
	t_piv		pivot;
	t_node		*temp;

	count = 0;
	temp = (push_swap->stack_a)->head;
	init_pivot(&pivot);
	pivot.position = (push_swap->stack_a)->head;
	while (pivot.position)
	{
		while (temp)
		{
			if (temp != pivot.position && NB(temp)->nb < NB(pivot.position)->nb)
				pivot.low++;
			temp = temp->next;
		}
		pivot_up(push_swap, &pivot);
		pivot_distance(&pivot);
		ft_doublelink_add(push_swap->stack_pivot, &pivot, sizeof(t_piv));
		pivot.position = pivot.position->next;
		pivot.low = 0;
		pivot.up = 0;
		pivot.distance = 0;
		temp = (push_swap->stack_a)->head;
	}
}

void			pivot_up(t_pushswap *push_swap, t_piv *pivot)
{
	if ((int)(push_swap->stack_a)->length > pivot->low)
		pivot->up = (int)(push_swap->stack_a)->length - pivot->low - 1;
	else
		pivot->up = pivot->low - (int)(push_swap->stack_a)->length - 1;
}

void			pivot_distance(t_piv *pivot)
{
	if (pivot->up >= pivot->low)
		pivot->distance = pivot->up - pivot->low;
	else
		pivot->distance = pivot->low - pivot->up;
}

int				which_pivot(t_pushswap *push_swap, int value)
{
	t_node		*temp;
	t_node		*pivot;

	temp = push_swap->stack_pivot->head;
	pivot = push_swap->stack_pivot->head;
	while (temp)
	{
		if (PIVOT(pivot)->distance > PIVOT(temp)->distance)
			pivot = temp;
		temp = temp->next;
	}
	if (value == 1)
		return (NB(PIVOT(pivot)->position)->nb);
	else
		return (PIVOT(pivot)->low);
}