# include "push_swap.h"

void			free_everything(t_stack *a, t_stack *b, t_args *info, t_list *instruct)
{
	free_stack(a);
	free_stack(b);
	free(info);
	instruct = NULL;
//	free (instruct);
}

void			print_final_stack(t_stack **a)
{
	t_stack 		*p;

	p = *a;
	while (p)
	{
		ft_printf("%d\n", p->data);
		p = p->next;
	}
}

void			print_out(t_list *instruct, t_stack **a)
{
	while (instruct)
	{
		ft_printf("%s\n", instruct->content);
		instruct = instruct->next;
	}
	(void)a;
//	print_final_stack(a);
}

void			error_managment(int key, intmax_t i, char *str)
{
	if (key == 1)
		ft_printf("Usage: ./push_swap 2 4 9 42...\nPlease enter at least one integer\n");
	else if (key == 2)
		ft_printf("Error: invalid argument -%s-\nI don't know how to deal with it:(\n", str);
	else if (key == 3)
		ft_printf("Error: argument -%jd- is too big for an int\nI don't know how to deal with it:(\n", i);
	else if (key == 4)
		ft_printf("Error: there are duplicates of -%jd- in the input\nI don't know how to deal with it:(\n", i);
	exit(EXIT_FAILURE);
}

int				push_all_in_a(t_stack **a, t_stack **b, t_list **instruct)
{
	t_stack 	*pp;

	pp = *b;
	while (pp)
	{
		s_push(a, b);
		stock_instruct(instruct, "pa");
		pp = pp->next;
	}
	return (42);
}

int				main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_args		*info;
	t_list		*instruct;

	stack_a = NULL;
	stack_b = NULL;
	if (!(info = malloc(sizeof(t_args))))
		ft_malloc_error(__LINE__, __FILE__);
	instruct = NULL;
	if (ac > 1)
	{
		get_user_data(ac, av, &stack_a, info);
		info->size = stack_len(&stack_a);
		sort_this_shit(&stack_a, &stack_b, info, &instruct);
//		push_all_in_a(&stack_a, &stack_b, &instruct);
//		print_final_stack(&stack_a);
		print_final_stack(&stack_b);
		free_everything(stack_a, stack_b, info, instruct);
	}
	else
		error_managment(1, 0, NULL);
	return (0);
}
