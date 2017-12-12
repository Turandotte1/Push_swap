#include "push_swap.h"

int				is_sorted_up(t_stack **stack)
{
	t_stack		*list;

	list = *stack;
	while (list && list->next)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

int				is_sorted_down(t_stack **stack)
{
	t_stack		*list;

	list = *stack;
	while (list && list->next)
	{
		if (list->data < list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

int 			stack_len(t_stack *stack)
{
	int			len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int				ft_push(t_stack **top, int data)
{
	t_stack		*new;

	if (!(new = malloc(sizeof(t_stack))))
		ft_malloc_error(__LINE__, __FILE__);
	new->data = data;
	new->next = (*top == NULL ? NULL : *top);
	*top = new;
	return (1);
}

void			stock_instruct(t_list **instruct, char *str)
{
	t_list		*temp;

	temp = *instruct;
	if (*instruct == NULL)
		*instruct = ft_lstnew(str, ft_strlen(str) + 1);
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(str, ft_strlen(str) + 1);
	}
}