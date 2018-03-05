#include "push_swap.h"

void				free_this_shit(t_stack **head)
{
	t_stack			*current;
	t_stack			*remove;

	if (head == NULL)
		return ;
	if (*head == NULL)
		return ;
	current = *head;
	while (current->next)
	{
		remove = current;
		current = current->next;
		free(remove);
	}
	free(current);
	*head = NULL;
}

static int			compare(int data, t_stack **a)
{
	t_stack *temp;

	temp = *a;
	while (temp)
	{
		if (data > temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int					find_min(t_stack **a)
{
	int				min;
	t_stack			*temp;

	temp = *a;
	min = 0;
	while (temp)
	{
		if (compare(temp->data, a))
			break ;
		min++;
		temp = temp->next;
	}
	return (min);
}

int					check_if_sorted(t_stack **a, t_stack **b)
{
	t_stack 		*first;
	t_stack 		*second;

	if (*b)
		return (0);
	first = *a;
	second = (*a)->next;
	while (second)
	{
		if (first->data > second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}

t_stack				*ft_create_elem(int data)
{
	t_stack			*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (new);
	new->data = data;
	new->next = NULL;
	return (new);
}