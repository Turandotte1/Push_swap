#include "push_swap.h"

int			fill_stack_a(char **tab, t_stack **stack)
{
	int 	i;

	i = 0;
	while (tab[i])
		i++;
	while (i)
	{
		if (ft_isdigit(tab[i][0]) || ft_isdigit(tab[i][1]))
		{
			if (!(ft_push(stack, ft_atoi(tab[i]))))
				return (ft_errors_managment());
		}
		i--;
	}
	return (0);
}

void	ps_qsort(t_stack **a, t_stack **b, t_list **inst, t_qsort qsort)
{
	qsort.push = 0;
	qsort.rot = 0;
	if (qsort.len <= 2)
	{
		return (do_we_swap(a, NULL, inst));
	}
	qsort.pivot = get_pivot(*a, qsort.len);
	push_and_rot(a, b, inst, &qsort);
	qsort.big_len = stack_len(*a);
	while (qsort.rot-- && qsort.big_len != qsort.len)
	{
		if (exec_instruction(REVROT_A, a, b, inst) == false)
			handle_error(*a, *b, *inst, NULL);
	}
	ps_qsort(a, b, inst, qsort);
	qsort.len = qsort.push;
	ps_rev_qsort(a, b, inst, qsort);
	while (qsort.push--)
	{
		if (exec_instruction(PUSH_A, a, b, inst) == false)
			handle_error(*a, *b, *inst, NULL);
	}
}

void	push_and_rot(t_stack **a, t_stack **b, t_list **inst, t_qsort *qsort)
{
	int sorts;

	sorts = how_many_sorts(*a, qsort->pivot, qsort->len);
	while (sorts)
	{
		if ((*a)->data < qsort->pivot)
		{
			if (exec_instruction(PUSH_B, a, b, inst) == false)
				handle_error(*a, *b, *inst, NULL);
			qsort->len--;
			qsort->push++;
			sorts--;
		}
		else
		{
			if (exec_instruction(ROT_A, a, b, inst) == false)
			{
				handle_error(*a, *b, *inst, NULL);
			}
			qsort->rot++;
		}
	}
}

void	ps_rev_qsort(t_stack **a, t_stack **b, t_list **inst, t_qsort qsort)
{
	qsort.push = 0;
	qsort.rot = 0;
	qsort.tmp_len = qsort.len;
	if (qsort.len <= 2)
	{
		return (do_we_swap(NULL, b, inst));
	}
	qsort.pivot = get_pivot(*b, qsort.len);
	rev_push_and_rot(a, b, inst, &qsort);
	qsort.len = qsort.push;
	ps_qsort(a, b, inst, qsort);
	qsort.big_len = stack_len(*b);
	while (qsort.rot-- && qsort.big_len != qsort.len)
	{
		if (exec_instruction(REVROT_B, a, b, inst) == false)
			handle_error(*a, *b, *inst, NULL);
	}
	qsort.len = qsort.tmp_len - qsort.push;
	ps_rev_qsort(a, b, inst, qsort);
	while (qsort.push--)
	{
		if (exec_instruction(PUSH_B, a, b, inst) == false)
			handle_error(*a, *b, *inst, NULL);
	}
}

void	rev_push_and_rot(t_stack **a, t_stack **b, t_list **ins, t_qsort *qsort)
{
	int sorts;

	sorts = rev_how_many_sort(*b, qsort->pivot, qsort->len);
	while (sorts)
	{
		if ((*b)->data > qsort->pivot)
		{
			if (exec_instruction(PUSH_A, a, b, ins) == false)
			{
				handle_error(*a, *b, *ins, NULL);
			}
			qsort->push++;
			sorts--;
		}
		else
		{
			if (exec_instruction(ROT_B, a, b, ins) == false)
			{
				handle_error(*a, *b, *ins, NULL);
			}
			qsort->rot++;
		}
	}
}

