#include "push_swap.h"

void			sa(t_stack **a, t_stack **b, t_args *args)
{
	t_stack 	*second;

	(void)*b;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	if (args->print)
		write(1, "sa\n", 3);
	if (args->debug)
		debug_opt(a, b, "sa");
}

void			sb(t_stack **a, t_stack **b, t_args *args)
{
	t_stack 	*second;

	(void)*a;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	second = (*b)->next;
	(*b)->next = second->next;
	second->next = *b;
	*b = second;
	if (args->print)
		write(1, "sb\n", 3);
	if (args->debug)
		debug_opt(a, b, "sb");
}

void			ss(t_stack **a, t_stack **b, t_args *args)
{
	args->print = 0;
	sa(a, b, args);
	sb(a, b, args);
	args->print = 1;
	if (!args->checker)
		write(1, "ss\n", 3);
	if (args->debug)
		debug_opt(a, b, "ss");
}