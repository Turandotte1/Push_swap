#include "push_swap.h"

static void			print_a_b(t_stack **temp_a, t_stack **temp_b)
{
	ft_printf("|           |             |\n");
	ft_printf("|%4d       |    %4d   |\n", (*temp_a)->data, (*temp_b)->data);
	ft_printf("|__________ |______________|\n");
	*temp_a = (*temp_a)->next;
	*temp_b = (*temp_b)->next;
}

static void			print_a(t_stack **temp_a)
{
	ft_printf("|           |             |\n");
	ft_printf("|%5d      |             |\n", (*temp_a)->data);
	ft_printf("|___________|_____________|\n");
	*temp_a = (*temp_a)->next;
}

static void			print_b(t_stack **temp_b)
{
	ft_printf("|           |             |\n");
	ft_printf("|         |      %4d   |\n", (*temp_b)->data);
	ft_printf("|___________|____________|\n");
	*temp_b = (*temp_b)->next;
}

static void			print_stacks(t_stack **a, t_stack **b)
{
	t_stack			*temp_a;
	t_stack 		*temp_b;

	temp_a = *a;
	temp_b = *b;
	ft_printf("**** A *** STACK *** B ****\n");
	while (temp_a || temp_b)
	{
		if (temp_a && temp_b)
			print_a_b(&temp_a, &temp_b);
		if (temp_a && !temp_b)
			print_a(&temp_a);
		if (!temp_a && temp_b)
			print_b(&temp_b);
	}
}

void 				debug_opt(t_stack **a, t_stack **b, char *str)
{
	ft_printf("Stack state %s action\n", str);
	print_stacks(a, b);
//	if (args->colors)
}