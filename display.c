#include "push_swap.h"

void				print_it_out(t_pushswap *push_swap, t_args *args, int sort)
{
	if ((push_swap->stack_op)->head == NULL)
		ft_printf("\nNo operations were executed\n");
	else
	{
		ft_printf("\nActions executed :\n");
		print_operations(push_swap->stack_op);
	}
	if (args->info == 1)
		which_sort(sort);
	if (args->num == 1)
		ft_printf("\nTotal number of operations : %d\n", push_swap->stack_op->length);
}

void				print_operations(t_double *op)
{
	t_node			*temp;

	temp = op->tail;
	while (temp)
	{
		ft_putstr(ACTIONS(temp)->name);
		if (temp->prev != NULL)
		{
			write(1, " ", 1);
			temp = temp->prev;
		}
		else
		{
			ft_printf("\n");
			break ;
		}
	}
}

void				which_sort(int sort)
{
	if (sort == 1)
		ft_printf("\nI've reversed small-sized pile to sort this stack\n");
	else if (sort == 2)
		ft_printf("\nI've used selection sort method to sort this stack\n");
	else if (sort == 3)
		ft_printf("\nI've used quick-sort method to sort this stack\n");
	else if (sort == 4)
		ft_printf("\nI've done only one swap to sort this stack\n");
}


void				debug_opt(t_pushswap *push_swap, char *op)
{
	if (op[0] != '\0')
		ft_printf("\nStack state after %s operation:", op);
	else
		ft_printf("\nStacks :");
	ft_putstr("\nA : ");
	stack_print(push_swap->stack_a);
	ft_putstr("\nB : ");
	stack_print(push_swap->stack_b);
	ft_putstr("\n");
}

void				stack_print(t_double *stack)
{
	t_node			*temp;

	temp = stack->head;
	while (temp)
	{
		ft_putnbr(NB(temp)->nb);
		if (temp->next)
			write(1, " ", 1);
		temp = temp->next;
	}
}
