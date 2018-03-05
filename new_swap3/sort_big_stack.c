#include "push_swap.h"

static void				renew_struct(t_weight *price, t_weight *temp_price)
{
	price->ra = temp_price->ra;
	price->rra = temp_price->rra;
	price->rb = temp_price->rb;
	price->rrb = temp_price->rrb;
	price->total = temp_price->total;
}

static void				init_struct_price(t_weight *price)
{
	price->ra = 0;
	price->rb = 0;
	price->rra = 0;
	price->rrb = 0;
	price->total = 0;
}

static void				re_push_a(int b_len, t_stack **a, t_stack **b, t_args *args)
{
	int					min;

	min = find_min(b);
	if (b_len - min > min)
	{
		while (min + 1)
		{
			rb(a, b, args);
			min--;
		}
	}
	else
	{
		while (min < b_len - 1)
		{
			rrb(a, b, args);
			min++;
		}
	}
	while (*b)
		pa(a, b, args);
}

static void				less_costly(t_weight *price, t_stack **a, t_stack **b)
{
	int					a_len;
	int					position;
	t_weight			temp_price;
	t_stack				*temp_stack;

	temp_stack = *a;
	init_struct_price(&temp_price);
	position = 1;
	less_costly_a(price, position, a);
	less_costly_b(price, temp_stack->data, b);
	a_len = stack_len_calc(a);
	while (temp_stack)
	{
		less_costly_a(&temp_price, position, a);
		less_costly_b(&temp_price, temp_stack->data, b);
		if (temp_price.total < price->total)
			renew_struct(price, &temp_price);
		temp_stack = temp_stack->next;
		position++;
	}
}

void					sort_big_stack(t_stack **a, t_stack **b, t_args *args)
{
	int					b_len;
	t_weight			price;

	pb(a, b, args);
	pb(a, b, args);
	if ((*b)->data < (*b)->next->data)
		rb(a, b, args);
	while (*a)
	{
		init_struct_price(&price);
		less_costly(&price, a, b);
		start_rotation(&price, a, b, args);
	}
	b_len = stack_len_calc(b);
	re_push_a(b_len, a, b, args);
}