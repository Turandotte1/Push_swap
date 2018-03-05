/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:34:18 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 02:36:44 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rra(t_stack **a, t_stack **b, t_args *args)
{
	t_stack		*head;
	t_stack		*tail;

	(void)*b;
	if (!*a || !(*a)->next)
		return ;
	head = (*a)->next;
	tail = *a;
	while (head->next)
	{
		head = head->next;
		tail = tail->next;
	}
	head->next = *a;
	tail->next = NULL;
	*a = head;
	args->ops++;
	if (args->print)
		write(1, "rra\n", 4);
	if (args->debug)
		debug_opt(a, b, args);
}

void			rrb(t_stack **a, t_stack **b, t_args *args)
{
	t_stack		*head;
	t_stack		*tail;

	(void)*a;
	if (!*b || !(*b)->next)
		return ;
	head = (*b)->next;
	tail = *b;
	while (head->next)
	{
		head = head->next;
		tail = tail->next;
	}
	head->next = *b;
	tail->next = NULL;
	*b = head;
	args->ops++;
	if (args->print)
		write(1, "rrb\n", 4);
	if (args->debug)
		debug_opt(a, b, args);
}

void			rrr(t_stack **a, t_stack **b, t_args *args)
{
	rra(a, b, args);
	rrb(a, b, args);
	args->print = 1;
	args->ops -= 1;
	if (!args->checker)
		write(1, "rrr\n", 4);
	if (args->debug)
		debug_opt(a, b, args);
}
