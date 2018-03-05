/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:13:19 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 02:16:35 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					compare_data(int current, t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (current > temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static int			check_swap_first(t_stack **a)
{
	int				first;
	int				second;
	t_stack			*temp;

	temp = *a;
	first = temp->data;
	temp = temp->next;
	second = temp->data;
	if (second > first)
		return (0);
	temp = temp->next;
	while (temp)
	{
		if (temp->data < first || temp->data < second)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static int			check_piles(t_stack **a, t_stack **b)
{
	return (check_a(a) && check_b(b) ? 1 : 0);
}

void				selection_sort(t_stack **a, t_stack **b, t_args *args)
{
	int				min;

	while (!check_piles(a, b))
	{
		min = find_min(a);
		if (min && check_swap_first(a))
			sa(a, b, args);
		else
		{
			if (min > stack_len_calc(a) - min
					&& (min = stack_len_calc(a) - min))
				while (!check_piles(a, b) && min--)
					rra(a, b, args);
			else
				while (!check_piles(a, b) && min--)
					ra(a, b, args);
		}
		if (!check_piles(a, b))
			pb(a, b, args);
	}
	while (*b)
		pa(a, b, args);
}
