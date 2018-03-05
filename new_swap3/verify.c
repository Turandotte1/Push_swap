#include "push_swap.h"

int				check_a(t_stack **a)
{
	t_stack		*first;
	t_stack		*second;

	if (!*a)
		return (1);
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

int				check_b(t_stack **b)
{
	t_stack		*first;
	t_stack		*second;

	if (!*b)
		return (1);
	first = *b;
	second = (*b)->next;
	while (second)
	{
		if (first->data < second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}

int				check_duplicates(t_stack **a)
{
	int			temp_index;
	int			current_index;
	t_stack 	*temp;
	t_stack		*current;

	current_index = 1;
	current = *a;
	while (current)
	{
		temp = *a;
		temp_index = 1;
		while (temp->next)
		{
			if (current_index != temp_index && temp->data == current->data)
				return (0);
			temp_index++;
			temp = temp->next;
		}
		current = current->next;
		current_index++;
	}
	return (1);
}

int				stack_len_calc(t_stack **a)
{
	int			len;
	t_stack		*temp;

	if (!*a)
		return (0);
	len = 1;
	temp = *a;
	while (temp->next)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

void			stack_fill(t_stack **head, int data)
{
	t_stack			*new;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = ft_create_elem(data);
		return ;
	}
	new = *head;
	while (new->next != NULL)
		new = new->next;
	new->next = ft_create_elem(data);
}