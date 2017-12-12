# include "push_swap.h"

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

void			free_it(t_stack *a, t_stack *b, t_args *info, t_list *instruct)
{
	t_list		*temp;

	temp = NULL; 
	free_stack(a);
	free_stack(b);
	free(info);
	while (instruct)
	{
		temp = instruct->next;
		free(instruct);
		instruct = temp;
	}
}

void			error_managment(int key, intmax_t i, char *str)
{
	if (key == 1)
		ft_printf("Error: invalid argument -%s-\nI don't know how to deal with it:(\n", str);
	else if (key == 2)
		ft_printf("Error: argument -%jd- is too big for an int\nI don't know how to deal with it:(\n", i);
	else if (key == 3)
		ft_printf("Error: there are duplicates of -%jd- in the input\nI don't know how to deal with it:(\n", i);
	ft_printf("Usage: ./push_swap 2 4 9 42...\nPlease enter at least one integer or verify the input\n");
	exit(EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_args		*info;
	t_list		*instruct;

	a = NULL;
	b = NULL;
	if (!(info = malloc(sizeof(t_args))))
		ft_malloc_error(__LINE__, __FILE__);
	instruct = NULL;
	if (ac > 1)
	{
		get_user_data(ac, av, &a, info);
		if (!(is_sorted_up(&a)))
			sort_this_shit(&a, &b, info, &instruct);
//		print_it_out(instruct, info, &a, &b);
		free_it(a, b, info, instruct);
	}
	else
		error_managment(0, 0, NULL);
	return (0);
}
