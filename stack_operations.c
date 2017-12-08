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

void			s_swap(t_stack *a, t_stack *b)
{
	int			temp;

	if (a && a->next)
	{
		temp = a->data;
		a->data = a->next->data;
		a->next->data = temp;
	}
	if (b && b->next)
	{
		temp = b->data;
		b->data = b->next->data;
		b->next->data = temp;
	}
}

int				s_push(t_stack **dest, t_stack **src)
{
	if (src)
	{
		ft_push(dest, (*src)->data);
		s_pop(src);
	}
	return (1);
}

int				s_rotate(t_stack **a, t_stack **b)
{
	t_stack 	*new_end;
	
	if (a && *a && (*a)->next)
	{
		new_end = *a;
		while (new_end->next)
			new_end = new_end->next;
		if (!(new_end->next = malloc(sizeof(t_stack))))
			ft_malloc_error(__LINE__, __FILE__);
		new_end->next->data = (*a)->data;
		new_end->next->next = NULL;
		s_pop(a);
	}
	if (b && *b && (*b)->next)
	{
		new_end = *b;
		while (new_end->next)
			new_end = new_end->next;
		if (!(new_end->next = malloc(sizeof(t_stack))))
			ft_malloc_error(__LINE__, __FILE__);
		new_end->next->data = (*b)->data;
		new_end->next->next = NULL;
		s_pop(b);
	}
	return (1);
}

int				s_reverse_rotate(t_stack **a, t_stack **b)
{
	t_stack 	*new_begin;

	if (a && *a && (*a)->next)
	{
		new_begin = *a;
		while (new_begin->next->next)
			new_begin = new_begin->next;
		ft_push(a, new_begin->next->data);
		free(new_begin->next);
		new_begin->next = NULL;
	}
	if (b && *b && (*b)->next)
	{
		new_begin = *b;
		while (new_begin->next->next)
			new_begin = new_begin->next;
		ft_push(b, new_begin->next->data);
		free(new_begin->next);
		new_begin->next = NULL;
	}
	return (1);
}

