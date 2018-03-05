#include "push_swap.h"

static int			input_moves(t_stack **a, t_stack **b, int fd, t_args *args)
{
	char			*line;
	int				struct_index;
	t_checker		tab[11];

	init_checker_tab(&*tab);
	fd = 0;
	while ((get_next_line(0, &line) > 0) && !(struct_index = 0))
	{
		while (struct_index < 11)
		{
			if (!ft_strcmp(line, tab[struct_index].op))
			{
				args->print = 0;
				args->checker = 1;
				tab[struct_index].ft(a, b, args);
				break ;
			}
			struct_index++;
		}
		if (struct_index == 11)
			return (0);
		free(line);
	}
	free(line);
	check_if_worked(a, b);
	return (1);
}

static int			init_stack_a(t_stack **a, char *arg)
{
	int				index;

	index = 0;
	while (arg[index])
	{
		while (arg[index] == ' ')
			index++;
		if (ft_atoi_max(&arg[index]) > INT_MAX || ft_atoi_max(&arg[index]) < INT_MIN)
			return (0);
		stack_fill(a, ft_atoi_max(&arg[index]));
		while (arg[index] && arg[index] != ' ')
			index++;
		while (arg[index] && arg[index] == ' ')
			index++;
	}
	return (!check_duplicates(a) ? 0 : 1);
}

static int			convert_args(int fd, t_args *args, int ac, char **av)
{
	int				i;
	t_stack 		*a;
	t_stack 		*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (args->total)
		i += args->total;
	if (fd)
		i++;
	if (!(check_args(ac, av, i)))
	{
//		printf("\ncaca\n");
		return (0);
	}
	while (i < ac)
	{
		if (!(init_stack_a(&a, av[i])))
			return (0);
		i++;
	}
	if (!input_moves(&a, &b, fd, args))
	{
//		printf("\ncaca2\n");
		return (0);
	}
	free_this_shit(&a);
	return (1);
}

static int 			opt_browse(char *str, t_args *args)
{
	int 		i;

	i = 1;
	while (str[i])
	{
		if (!(ft_strchr(OPTIONS, str[i])))
		{
			ft_printf("unknown option %s\n", str[i]);
			write(1, "usage: ./checker [-vnc] [filename] [ints to sort...]\n", 45);
			return (0);
		}
		if (str[i] == 'v' && (args->debug = 1))
			args->total++;
		if (str[i] == 'n' && (args->num = 1))
			args->total++;
		if (str[i] == 'c' && (args->colors = 1))
			args->total++;
		i++;
	}
	return (1);
}

int					main(int ac, char **av)
{
	int				fd;
	int				i;
	t_args			args;

	i = 1;
	init_args(&args);
	if (ac < 2)
		return (0);
	if (av[1][0] == '-' && av[1][1])
	{
		if (!(opt_browse(av[1], &args)))
		{
			printf("\ncaca\n");
			return (0);
		}
		if (args.total)
			i++;
	}
	if ((fd = open(av[i], O_RDONLY)) == -1)
		fd = 0;
	else
		i++;
	if (ac < i + 1)
	{
		write(1, "usage: ./checker [-vnc] [filename] [ints to sort...]\n", 45);
		return (0);
	}
	if (!convert_args(fd, &args, ac, av))
		write(2, "Error\n", 6);
	return (0);
}