#include "push_swap.h"

void			rra_op(t_pushswap *push_swap)
{
	t_node		*push;
	t_act		op;

	push = NULL;
	op.name = NULL;
	if ((push_swap->stack_a)->length == 0)
		return ;
	op.name = ft_strdup("rra");
	push = (push_swap->stack_a)->head;
	if ((push_swap->stack_a)->length > 1)
	{
		(push_swap->stack_a)->head = (push_swap->stack_a)->head->next;
		(push_swap->stack_a)->head->prev = NULL;
		(push_swap->stack_a)->tail->next = push;
		push->prev = (push_swap->stack_a)->tail;
		(push_swap->stack_a)->tail = push;
		push->next = NULL;
	}
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}

void			rrb_op(t_pushswap *push_swap)
{
	t_node		*push;
	t_act		op;

	push = NULL;
	op.name = NULL;
	if ((push_swap->stack_b)->length == 0)
		return ;
	op.name = ft_strdup("rrb");
	push = (push_swap->stack_b)->head;
	if ((push_swap->stack_b)->length > 1)
	{
		(push_swap->stack_b)->head = (push_swap->stack_b)->head->next;
		(push_swap->stack_b)->head->prev = NULL;
		(push_swap->stack_b)->tail->next = push;
		push->prev = (push_swap->stack_b)->tail;
		(push_swap->stack_b)->tail = push;
		push->next = NULL;
	}
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}

void			rrr_op(t_pushswap *push_swap)
{
	t_act		op;
	int			op_rra;
	int			op_rrb;

	op.name = NULL;
	op_rra = 0;
	op_rrb = 0;
	if ((push_swap->stack_a)->length >= 1)
		op_rra = 1;
	if ((push_swap->stack_b)->length >= 1)
		op_rrb = 1;
	if (op_rra != 0 || op_rrb != 0)
		op.name = ft_strdup("rrr");
	rra_op(push_swap);
	rrb_op(push_swap);
	if (op_rra == 1)
		free_ops(&push_swap->stack_op, (push_swap->stack_op)->tail);
	if (op_rrb == 1)
		free_ops(&push_swap->stack_op, (push_swap->stack_op)->tail);
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}