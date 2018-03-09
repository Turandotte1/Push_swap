/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:12:09 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 02:13:11 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (!receive_args(&a, ac, av) || (!(check_args(ac, av, 1))))
	{
		free_this_shit(&a);
		if (!args.checker)
			write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	choose_sort(&a, &b, &args);
	free_this_shit(&a);
	free_this_shit(&b);
	return (0);
}
