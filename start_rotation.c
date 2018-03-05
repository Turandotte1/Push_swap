/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:11:03 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 02:12:50 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		rr_op(t_weight **price, t_stack **a, t_stack **b, t_args *args)
{
	while ((*price)->ra && (*price)->rb)
	{
		args->print = 0;
		rr(a, b, args);
		(*price)->ra--;
		(*price)->rb--;
	}
}

static void		rrr_op(t_weight **price, t_stack **a, t_stack **b, t_args *args)
{
	while ((*price)->rra && (*price)->rrb)
	{
		args->print = 0;
		rrr(a, b, args);
		(*price)->rra--;
		(*price)->rrb--;
	}
}

void			start_rotation(t_weight *price, t_stack **a, t_stack **b,
															t_args *args)
{
	if (price->ra && price->rb)
		rr_op(&price, a, b, args);
	if (price->rra && price->rrb)
		rrr_op(&price, a, b, args);
	while (price->ra--)
		ra(a, b, args);
	while (price->rb--)
		rb(a, b, args);
	while (price->rra--)
		rra(a, b, args);
	while (price->rrb--)
		rrb(a, b, args);
	pb(a, b, args);
}
