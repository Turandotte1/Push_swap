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

int				presort(t_pushswap *push_swap, t_args *args, int *sort)
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
		temp = tmp->next;
	}
	sa(push_swap);
	if (args->v == 1)
		debug_opt(push_swap, "sa");
	rra(push_swap);
	if (options->v == 1)
		debug_opt(push_swap, "rra");
	*sort = 1;
	return (1);
}