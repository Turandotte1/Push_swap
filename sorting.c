#include "push_swap.h"

int			last_pointer_data(t_stack *stack)
{
	int 	last;

	last = 0;
	while (stack->next)
		stack = stack->next;
	last = stack->data;
	return (last);
}

int				push_all_in_a(t_stack **a, t_stack **b, t_list **instruct)
{
	t_stack 	*pp;

	pp = *b;
	while (pp)
	{
		s_push(a, b);
		stock_instruct(instruct, "pa");
		pp = pp->next;
	}
	return (42);
}

void 			ascending_check(t_stack **a, t_stack **b)
{
 	if ((*a)->first > (*a)->second)
 	{
 		s_swap(*a, NULL);
 		s_rotate(a, NULL);
 	//	print_final_stack(a);
 	//	printf("\n");
 		//stock_instruct("sa");
 	}
 	else if ((*a)->first < (*a)->second && (*a)->first > (*a)->last)
 	{
 		s_reverse_rotate(a, NULL);
 		a = &(*a)->next;
 	//	print_final_stack(a);
 	//	printf("\n");
 		//stock_instruct("rra");
 	}
 	else if ((*a)->first < (*a)->second && (*a)->first < (*a)->last)
 	{
 		if ((*a)->first >= (*a)->pivot)
 		{
 			s_rotate(a, NULL);
 			a = &(*a)->next;
 	//		print_final_stack(a);
 	//		printf("\n");
 			//stock_instruct("ra");
 		}
 		else
 		{
 			s_push(b, a);
 			a = &(*a)->next;
 			print_final_stack(b);
 	//		printf("\n");
 			//stock_instruct("pb");
 		}
 	}
}

void			descending_check(t_stack **stack)
{	
 	if ((*stack)->first < (*stack)->second)
 	{
 		s_swap(*stack, NULL);
 		//stock;
 	}
 	else if ((*stack)->first > (*stack)->second && (*stack)->first < (*stack)->last)
 	{
 		s_reverse_rotate(stack, NULL);
 		//stock_instruct("rrb");
 	}
 	else
 	{
 		s_rotate(stack, NULL);
 		//stock_instruct("rb");
 	}
}

void			print_final_stack(t_stack **a)
{
	t_stack 		*p;

	p = *a;
	while (p)
	{
		ft_printf("%d\n", p->data);
		p = p->next;
	}
}

void			sort_this_shit(t_stack **a, t_stack **b, t_args *info, t_list **instruct)
{
	int 			len;

	len = stack_len(*a);
	(*a)->pivot = pivot_found(*a, len);
	while (len-- > 2)
	{
		(*a)->first = (*a)->data;
		printf("at rot #%d first is %d\n", len, (*a)->first);
		(*a)->second = (*a)->next->data;
		(*a)->last = last_pointer_data(*a);
		ascending_check(a, b);
//		if (b)
//		{
//			(*b)->first = (*b)->data;
//			(*b)->second = (*b)->next->data;
//			(*b)->last = last_pointer_data(*b);
//			descending_check(b);
//			b = &(*b)->next;
//		}
	}
//	push_all_in_a(a, b, instruct);
	print_final_stack(a);
	print_final_stack(b);
	info = NULL;
	instruct = NULL;
}