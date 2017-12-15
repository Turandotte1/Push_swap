void	display_usage(void)
{
	ft_putendl("usage: ./push_swap 1 2 3 4... [-qsort] or [-ssort]");
	ft_putendl("[-qsort]: Forces the use of a quick sort algorithm.");
	ft_putendl("[-ssort]: Forces the use of a selection sort algorithm.");
	ft_putendl("By default the program will choose the most optimized algorithm "
				"according to the number of integers.");
}

void	print_instructions(t_list *i)
{
	while (i != NULL)
	{
		ft_putendl(i->content);
		i = i->next;
	}
}
void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int				sort_it(t_stack **a, t_stack **b, t_list **instruct, t_options *opt)
{
	t_sort 		info;

	info.size = stack_size(*a);
	if (is_sorted_up(*a) || my_quicksort(a, b, inst, data))
		return (1);
	return (0);
}

int				parse_it(int ac, char **av, t_stack **stack, t_args **opt)
{
	char 		**tab;

	tab = NULL;
	if (!(*opt = malloc(sizeof(t_options))))
		return (ft_malloc_error(__FILE__,__LINE__));
	tab = tab_maker(ac, av);	
	arguments_init_check(tab, opt);
	length_check(tab);
	duplicate_check(tab);
	fill_stack_a(tab, stack);
	free_tab(tab);
	return (0);
}

int				main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_list		*instruct;
	t_args		*opt;

	a = NULL;
	b = NULL;
	instruct = NULL;
	opt = NULL;
	if (ac > 1)
	{
		parse_it(ac, av, &a, &opt);


///////////////////////////////////////////////////		
		sort_it(&a, &b, opt, &instruct);
		optimize_it(instruct)
		print_it(instruct);
		free_it(a, b, instruct, opt);
	}
	else
//		display_usage(); -->error managment
	return (0);
}
