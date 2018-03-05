/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:02:59 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 07:23:39 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			check_str(char *str)
{
	int				i;
	int				size;
	int				check;

	check = 0;
	i = 0;
	size = ft_strlen(str);
	if (size == 0)
		return (0);
	while (i < size)
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != ' ' &&
				!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (ft_isdigit(str[i]))
			check++;
		i++;
	}
	return ((check) ? 1 : 0);
}

void				init_args(t_args *args)
{
	args->debug = 0;
	args->colors = 0;
	args->print = 1;
	args->checker = 0;
	args->total = 0;
	args->num = 0;
	args->ops = 0;
	args->execution_time = 0;
	args->start = clock();
}

void				init_checker_tab(t_checker *tab)
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

int					check_args(int ac, char **av, int index)
{
	int				cur_index;

	while (index < ac)
	{
		if (!check_str(av[index]))
			return (0);
		cur_index = 1;
		while (cur_index < ac)
		{
			if (index == cur_index)
				cur_index++;
			if (index < ac - 1 && !ft_strcmp(av[index], av[cur_index]))
				return (0);
			cur_index++;
		}
		index++;
	}
	return (1);
}

void				check_if_worked(t_stack **a, t_stack **b, t_args *args)
{
	t_stack			*first;
	t_stack			*second;
	int				test;

	test = 0;
	if ((first = *a) && *b
		&& (test = 1))
		if (args->colors)
			write(1, RED, ft_strlen(RED));
	while (!test && first->next && (second = first->next))
	{
		if (first->data > second->data)
			if (args->colors && (test = 1))
				write(1, RED, ft_strlen(RED));
		first = first->next;
	}
	if (!test && args->colors)
		write(1, BOLD_GREEN, ft_strlen(BOLD_GREEN));
	write(1, test ? "KO\n" : "OK\n", 3);
	if (args->colors)
		write(1, END, ft_strlen(END));
	if (args->num && !test)
		print_info(args);
}
