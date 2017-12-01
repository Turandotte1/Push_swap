#include "push_swap.h"

void			s_pop(t_stack **top)
{
	t_stack 	*temp;

	if (*top)
	{
		temp = *top;
		*top = temp->next;
		free(temp);
	}
}

int				s_push(t_stack **dest, t_stack **src)
{
	if (src)
	{
		ft_push(dest, (*src)->data);
		s_pop(src);
	}
	return (42);
}

int				s_rotate(t_stack **stack)
{
	t_stack 	*new_end;
	
	new_end = *stack;
	while (new_end->next)
		new_end = new_end->next;
	if (!(new_end->next = malloc(sizeof(t_stack))))
		ft_malloc_error(__LINE__, __FILE__);
	new_end->next->data = (*stack)->data;
	new_end->next->next = NULL;
	s_pop(stack);
	return (42);
}

int				s_reverse_rotate(t_stack **stack)
{
	t_stack 	*new_begin;

	if (stack && *stack && (*stack)->next)
	{
		new_begin = *stack;
		while (new_begin->next->next)
			new_begin = new_begin->next;
		ft_push(stack, new_begin->next->data);
		free(new_begin->next);
		new_begin->next = NULL;
	}
	return (42);
}

int				s_swap(t_stack *stack)
{
	int			temp;

	if (stack && stack->next)
	{
		temp = stack->data;
		stack->data = stack->next->data;
		stack->next->data = temp;
	}
	return (42);
}