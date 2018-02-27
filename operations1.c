#include "push_swap.h"

void			sa_op(t_pushswap *push_swap)
{
	int			cp;
	t_node		*temp;
	t_act		op;

	cp = 0;
	temp = (push_swap->stack_a)->tail;
	op.name = NULL;
	if ((push_swap->stack_a)->length <= 1)
		return ;
	else
	{
		op.name = ft_strdup("sa");
		cp = NB(temp)->nb;
		NB(temp)->nb = NB(temp->prev)->nb;
		NB(temp->prev)->nb = cp;
		ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
	}
}

void			sb_op(t_pushswap *push_swap)
{
	int			cp;
	t_node		*temp;
	t_act		op;

	cp = 0;
	temp = (push_swap->stack_b)->tail;
	op.name = NULL;
	if ((push_swap->stack_b)->length <= 1)
		return ;
	else
	{
		op.name = ft_strdup("sb");
		cp = NB(temp)->nb;
		NB(temp)->nb = NB(temp->prev)->nb;
		NB(temp->prev)->nb = cp;
		ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
	}
}

void			ss_op(t_pushswap *push_swap)
{
	t_act		op;
	int			op_sa;
	int			op_sb;

	op.name = NULL;
	op_sa = 0;
	op_sb = 0;
	if ((push_swap->stack_a)->length > 1)
		op_sa = 1;
	if ((push_swap->stack_b)->length > 1)
		op_sb = 1;
	if (op_sa != 0 || op_sb != 0)
		op.name = ft_strdup("ss");
	else
		return ;
	sa_op(push_swap);
	sb_op(push_swap);
	if (op_sa == 1)
		free_ops(&push_swap->stack_op, (push_swap->stack_op)->tail);
	if (op_sb == 1)
		free_ops(&push_swap->stack_op, (push_swap->stack_op)->tail);
	ft_doublelink_add_head(push_swap->stack_op, &op, sizeof(t_act));
}

void			pa_src(t_double *stack)
{
	if (stack->length == 1)
	{
		stack->tail = NULL;
		stack->head = NULL;
	}
	else
	{
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
	}
	stack->length--;
}

void			pa_dst(t_double *stack, t_node *push)
{
	if (stack->length >= 1)
	{
		stack->tail->next = push;
		push->prev = stack->tail;
		stack->tail = push;
	}
	else
	{
		push->prev = NULL;
		stack->tail = push;
		stack->head = push;
	}
	stack->length++;
}
