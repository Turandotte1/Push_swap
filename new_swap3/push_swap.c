#include "push_swap.h"

static void			choose_sort(t_stack **a, t_stack **b, t_args *args)
{
	int				stack_len;

	stack_len = stack_len_calc(a);
	if (check_if_sorted(a, b))
		return ;
	if (stack_len > 10)
		sort_big_stack(a, b, args);
	else
	{
		if (stack_len == 3 && (*a)->next->next->data < (*a)->data &&
				(*a)->next->next->data < (*a)->next->data &&
				(*a)->data > (*a)->next->data)
			sa(a, b, args);
		selection_sort(a, b, args);
	}
}

static int			init_stack_a(t_stack **a, char *av)
{
	int		i;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if (ft_atoi_max(&av[i]) > INT_MAX || ft_atoi_max(&av[i]) < INT_MIN)
			return (0);
		stack_fill(a, ft_atoi(&av[i]));
		while (av[i] && av[i] != ' ')
			i++;
		while (av[i] && av[i] == ' ')
			i++;
	}
	return ((!check_duplicates(a)) ? 0 : 1);
}

static int			receive_args(t_stack **a, int ac, char **av)
{
	int				i;

	i = 1;
	while (i < ac)
	{
		if (!init_stack_a(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}

int					main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;
	t_args			args;

	a = NULL;
	b = NULL;
	init_args(&args);
	if (ac < 2)
		return (0);
	if (!receive_args(&a, ac, av))
	{
		free_this_shit(&a);
		return (0);
	}	
	choose_sort(&a, &b, &args);
	free_this_shit(&a);
	free_this_shit(&b);
	return (0);
}