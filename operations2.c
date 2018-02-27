#include "push_swap.h"

void			pa_op(t_pushswap *push_swap)
{
	t_node		*push;
	t_act		op;

	push = (push_swap->stack_b)->tail;
	op.name = ft_strdup("pa");
	pa_src(push_swap->stack_b);
	pa_dst(push_swap->stack_a, push);
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}

void			pb_op(t_pushswap *push_swap)
{
	t_node		*push;
	t_act		op;

	push = (push_swap->stack_a)->tail;
	op.name = ft_strdup("pb");
	pa_src(push_swap->stack_a);
	pa_dst(push_swap->stack_b, push);
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}

void			ra_op(t_pushswap *push_swap)
{
	t_node		*push;
	t_act		op;

	push = NULL;
	op.name = NULL;
	if ((push_swap->stack_a)->length == 0)
		return ;
	op.name = ft_strdup("ra");
	push = (push_swap->stack_a)->tail;
	if ((push_swap->stack_a)->length > 1)
	{
		(push_swap->stack_a)->tail = (push_swap->stack_a)->tail->prev;
		(push_swap->stack_a)->tail->next = NULL;
		(push_swap->stack_a)->head->prev = push;
		push->next = (push_swap->stack_a)->head;
		(push_swap->stack_a)->head = push;
		push->prev = NULL;
	}
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}

void			rb_op(t_pushswap *push_swap)
{
	t_node		*push;
	t_act		op;

	push = NULL;
	op.name = NULL;
	if ((push_swap->stack_b)->length == 0)
		return ;
	op.name = ft_strdup("rb");
	push = (push_swap->stack_b)->tail;
	if ((push_swap->stack_b)->length > 1)
	{
		(push_swap->stack_b)->tail = (push_swap->stack_b)->tail->prev;
		(push_swap->stack_b)->tail->next = NULL;
		(push_swap->stack_b)->head->prev = push;
		push->next = (push_swap->stack_b)->head;
		(push_swap->stack_b)->head = push;
		push->prev = NULL;
	}
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}

void			rr_op(t_pushswap *push_swap)
{
	t_act		op;
	int			op_ra;
	int			op_rb;

	op.name = NULL;
	op_ra = 0;
	op_rb = 0;
	if ((push_swap->stack_a)->length >= 1)
		op_ra = 1;
	if ((push_swap->stack_b)->length >= 1)
		op_rb = 1;
	if (op_ra != 0 || op_rb != 0)
		op.name = ft_strdup("rr");
	ra_op(push_swap);
	rb_op(push_swap);
	if (op_ra == 1)
		free_ops(&push_swap->stack_op, (push_swap->stack_op)->tail);
	if (op_rb == 1)
		free_ops(&push_swap->stack_op, (push_swap->stack_op)->tail);
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}