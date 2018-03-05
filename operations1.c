/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:34:12 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 02:35:54 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				pa(t_stack **a, t_stack **b, t_args *args)
{
	t_stack			*temp;

	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		temp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = temp;
	}
	args->ops++;
	if (args->print)
		write(1, "pa\n", 3);
	if (args->debug == 1)
		debug_opt(a, b, args);
}

void				pb(t_stack **a, t_stack **b, t_args *args)
{
	t_stack			*temp;

	if (!*a)
		return ;
	if (!*b)
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		temp = *b;
		*b = *a;
		*a = (*a)->next;
		(*b)->next = temp;
	}
	args->ops++;
	if (args->print)
		write(1, "pb\n", 3);
	if (args->debug == 1)
		debug_opt(a, b, args);
}

void				ra(t_stack **a, t_stack **b, t_args *args)
{
	t_stack			*head;
	t_stack			*tail;

	(void)*b;
	if (!*a || !(*a)->next)
		return ;
	head = (*a)->next;
	tail = *a;
	while (tail->next)
		tail = tail->next;
	tail->next = *a;
	(*a)->next = NULL;
	*a = head;
	args->ops++;
	if (args->print)
		write(1, "ra\n", 3);
	if (args->debug == 1)
		debug_opt(a, b, args);
}

void				rb(t_stack **a, t_stack **b, t_args *args)
{
	t_stack			*head;
	t_stack			*tail;

	(void)*a;
	if (!*b || !(*b)->next)
		return ;
	head = (*b)->next;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	tail->next = *b;
	(*b)->next = NULL;
	*b = head;
	args->ops++;
	if (args->print)
		write(1, "rb\n", 3);
	if (args->debug == 1)
		debug_opt(a, b, args);
}

void				rr(t_stack **a, t_stack **b, t_args *args)
{
	ra(a, b, args);
	rb(a, b, args);
	args->ops -= 1;
	if (!args->checker)
		write(1, "rr\n", 3);
	args->print = 1;
	if (args->debug == 1)
		debug_opt(a, b, args);
}
