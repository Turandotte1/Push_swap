/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:00:37 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/13 13:19:52 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void				init_checker_tab(t_checker *tab)
{
	tab[0].op = "sa";
	tab[0].ft = &sa;
	tab[1].op = "sb";
	tab[1].ft = &sb;
	tab[2].op = "ss";
	tab[2].ft = &ss;
	tab[3].op = "pa";
	tab[3].ft = &pa;
	tab[4].op = "pb";
	tab[4].ft = &pb;
	tab[5].op = "ra";
	tab[5].ft = &ra;
	tab[6].op = "rb";
	tab[6].ft = &rb;
	tab[7].op = "rr";
	tab[7].ft = &rr;
	tab[8].op = "rra";
	tab[8].ft = &rra;
	tab[9].op = "rrb";
	tab[9].ft = &rrb;
	tab[10].op = "rrr";
	tab[10].ft = &rrr;
}

static int				input_moves(t_stack **a, t_stack **b, int fd,
												t_args *args)
{
	char				*line;
	int					struct_index;
	t_checker			tab[11];

	init_checker_tab(tab);
	while ((get_next_line(fd, &line) > 0) && (struct_index = -1))
	{
		while (++struct_index < 11)
			if (!ft_strcmp(line, tab[struct_index].op))
			{
				args->print = 0;
				args->checker = 1;
				tab[struct_index].ft(a, b, args);
				break ;
			}
		if (ft_strdel(&line) && struct_index == 11)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	check_if_checker_worked(a, b, args);
	return (1);
}

static int				convert_args(int fd, t_args *args, int ac, char **av)
{
	int					i;
	t_stack				*a;
	t_stack				*b;

	i = 1;
	b = NULL;
	if (!(a = NULL) && args->total)
		i++;
	if (fd)
		i++;
	if (!(check_args(ac, av, i)))
		return (0);
	while (i < ac)
	{
		if (!(init_stack_a(&a, av[i])))
		{
			free_this_shit(&a);
			return (0);
		}
		i++;
	}
	if (!input_moves(&a, &b, fd, args))
		return (0);
	free_this_shit(&a);
	return (1);
}

static int				opt_browse(char *str, t_args *args)
{
	int					i;

	if (str[0] == '-' && str[1] && !(i = 0))
		while (str[++i])
		{
			if (ft_isdigit(str[i]) && !(args->total = 0))
				return (0);
			else if (str[i] == 'v' && !args->debug && (args->debug = 1))
				args->total++;
			else if (str[i] == 'n' && !args->num && (args->num = 1))
				args->total++;
			else if (str[i] == 'c' && !args->colors && (args->colors = 1))
				args->total++;
			else
			{
				ft_printf("Unknown option \"%s\"\n", str);
				ft_printf("Usage: ./checker [-vnc] [filename]\
						[ints to sort...]\n");
				exit(EXIT_FAILURE);
			}
		}
	return (args->total > 0);
}

int						main(int ac, char **av)
{
	int					fd;
	int					i;
	t_args				args;

	i = 1;
	init_args(&args);
	args.checker = 1;
	if (ac < 2)
		return (0);
	if (opt_browse(av[i], &args))
		i++;
	if ((fd = open(av[i], O_RDONLY)) == -1)
		fd = 0;
	else
		i++;
	if (ac < i + 1 && ft_printf("Usage: ./checker [-vnc]\
				[filename] [ints to sort...]\n"))
		exit(EXIT_FAILURE);
	if (!convert_args(fd, &args, ac, av))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (0);
}
