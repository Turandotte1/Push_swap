#include "push_swap.h"

int				is_sorted_up(t_stack **stack)
{
	t_stack		*list;

	list = *stack;
	while (list && list->next)
	{
		if (list->data > list->next->data)
			return (-1);
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
			return (-1);
		list = list->next;
	}
	return (1);
}

int 			stack_len(t_stack **stack)
{
	int			len;
	t_stack		*list;

	len = 0;
	list = *stack;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

void 			free_stack(t_stack *s)
{
	t_stack  	*temp;

	while (s)
	{
		temp = s->next;
		free(s);
		s = temp;
	}
}

int				ft_push(t_stack **top, int data)
{
	t_stack		*new;

	if (!(new = malloc(sizeof(t_stack))))
		ft_malloc_error(__LINE__, __FILE__);
	new->data = data;
	new->next = (top == NULL ? NULL : *top);
	*top = new;
	return (1);
}