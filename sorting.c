#include "push_swap.h"

void 			back_presort(t_stack **a, t_stack **b, t_args *info, t_list **instruct)
{
	int 		nb;

	nb = backwards_sorts_calc(b, info->pivot, info->size);
	while (nb)
	{
		if (info->pivot < (*b)->data)
		{
			s_push(a, b);
			stock_instruct(instruct, "pa");
			info->push++;
			nb--;
		}
		else
		{
			s_rotate(b);
			stock_instruct(instruct, "rb");
			info->rot++;
		}
	}
}

void 			backwards_sort(t_stack **a, t_stack **b, t_args *info, t_list **instruct)
{
//	if (!(is_sorted_down(b)))	
//	{
		info->push = 0;
		info->rot = 0;
		info->temp = info->size;
		printf("SIZE = %d\n", info->size);
		if (info->size < 3)
			return (small_len(NULL, b, instruct));
		info->pivot = pivot_found(*b, info->size);
		back_presort(a, b, info, instruct);
		info->size = info->push;
//		sort_this_shit(a, b, info, instruct);
		info->final_size = stack_len(b);
		while (info->rot-- && info->final_size != info->size)
		{
			s_reverse_rotate(b);
			stock_instruct(instruct, "rrb");
		}
		info->size = info->temp - info->push;
		backwards_sort(a, b, info, instruct);
		while (info->push--)
		{
			s_push(b, a);
			stock_instruct(instruct, "pb");
		}
//	}
}

void 			presort(t_stack **a, t_stack **b, t_args *info, t_list **instruct)
{
	int 		nb;

	nb = sorts_calc(a, info->pivot, info->size);
	while (nb)
	{
		if ((*a)->data < info->pivot)
		{
			s_push(b, a);
			stock_instruct(instruct, "pb");
			info->size--;
			info->push++;
			nb--;
		}
		else
		{
			s_rotate(a);
			stock_instruct(instruct, "ra");
			info->rot++;
		}
	}
}

void			sort_this_shit(t_stack **a, t_stack **b, t_args *info, t_list **instruct)
{
//	if (!(is_sorted_up(a)))
//	{
		info->push = 0;
		info->rot = 0;
		if (info->size < 3)
			return (small_len(a, NULL, instruct));
		info->pivot = pivot_found(*a, info->size);
		presort(a, b, info, instruct);
		info->final_size = stack_len(a);
		while (info->rot-- && info->final_size != info->size)
		{
			s_reverse_rotate(a);
			stock_instruct(instruct, "rra");
		}
		sort_this_shit(a, b, info, instruct);
		printf("PUSH1 = %d\n", info->push);
		info->size = info->push;
		backwards_sort(a, b, info, instruct);
		printf("PUSH = %d\n", info->push);
		while (info->push--)
		{
			s_push(a, b); 
			stock_instruct(instruct, "pa");
		}
//	}
}