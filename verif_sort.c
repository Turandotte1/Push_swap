/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 05:30:24 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/09 05:33:31 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					check_a(t_stack **a)
{
	t_stack		*first;
	t_stack		*second;

	if (!*a)
		return (1);
	first = *a;
	second = (*a)->next;
	while (second)
	{
		if (first->data > second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}

int					check_b(t_stack **b)
{
	t_stack		*first;
	t_stack		*second;

	if (!*b)
		return (1);
	first = *b;
	second = (*b)->next;
	while (second)
	{
		if (first->data < second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}

void				check_if_checker_worked(t_stack **a, t_stack **b,
													t_args *args)
{
	if (args->colors)
		write(1, RED, ft_strlen(RED));
	if (*b)
	{
		write(1, "KO\n", 3);
		if (args->colors)
			write(1, END, ft_strlen(END);
		exit(EXIT_FAILURE);
	}
	while (*a)
	{
		if (!(check_if_sorted(a, b)))
		{
			write(1, "KO\n", 3);
			if (args->colors)
				write(1, END, ft_strlen(END);
			exit(EXIT_FAILURE);
		}
		a = &(*a)->next;
	}
	if (args->colors)
		write(1, BOLD_GREEN, ft_strlen(BOLD_GREEN));
	write(1, "OK\n", 3);
	if (args->colors)
		write(1, END, ft_strlen(END));
	if (args->num)
		print_info(args);
}

int					check_if_sorted(t_stack **a, t_stack **b)
{
	t_stack			*first;
	t_stack			*second;

	if (*b)
		return (0);
	first = *a;
	second = (*a)->next;
	while (second)
	{
		if (first->data > second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}
