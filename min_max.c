#include "push_swap.h"

t_node			*find_min(t_double **stack)
{
	t_node		*temp;
	t_node		*min;

	temp = NULL;
	min = NULL;
	if ((*stack)->length < 1)
		return (NULL);
	temp = (*stack)->head;
	min = (*stack)->head;
	while (temp)
	{
		if (temp->next != NULL && NB(min)->nb > NB(temp->next)->nb)
			min = temp->next;
		temp = temp->next;
	}
	return (min);
}

t_node			*find_max(t_double **stack)
{
	t_node		*temp;
	t_node		*max;

	temp = NULL;
	max = NULL;
	if ((*stack)->length < 1)
		return (NULL);
	temp = (*stack)->head;
	max = (*stack)->head;
	while (temp)
	{
		if (NB(max)->nb < NB(temp)->nb)
			max = temp;
		temp = temp->next;
	}
	return (max);
}