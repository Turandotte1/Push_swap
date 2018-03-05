/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:34:24 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 02:38:09 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sa(t_stack **a, t_stack **b, t_args *args)
{
	t_stack		*second;

	(void)*b;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	args->ops++;
	if (args->print)
		write(1, "sa\n", 3);
	if (args->debug)
		debug_opt(a, b, args);
}

void			sb(t_stack **a, t_stack **b, t_args *args)
{
	t_stack		*second;

	(void)*a;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	second = (*b)->next;
	(*b)->next = second->next;
	second->next = *b;
	*b = second;
	args->ops++;
	if (args->print)
		write(1, "sb\n", 3);
	if (args->debug)
		debug_opt(a, b, args);
}

void			ss(t_stack **a, t_stack **b, t_args *args)
{
	args->print = 0;
	sa(a, b, args);
	sb(a, b, args);
	args->print = 1;
	args->ops -= 1;
	if (!args->checker)
		write(1, "ss\n", 3);
	if (args->debug)
		debug_opt(a, b, args);
}
