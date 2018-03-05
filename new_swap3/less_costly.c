#include "push_swap.h"

void				less_costly_a(t_weight *price_a, int position, t_stack **a)
{
	int				stack_len;

	stack_len = stack_len_calc(a);
	if (position > stack_len - position)
	{
		price_a->rra = stack_len - position + 1;
		price_a->ra = 0;
	}
	else
	{
		price_a->ra = position - 1;
		price_a->rra = 0;
	}
}

static void			calculate_b_price(t_weight **price_b, int position, t_stack **b)
{
	int				stack_len;

	stack_len = stack_len_calc(b);
	if (position > stack_len - position)
	{
		(*price_b)->rb = 0;
		(*price_b)->rrb = stack_len - position + 1;
	}
	else
	{
		(*price_b)->rrb = 0;
		(*price_b)->rb = position - 1;
	}
}

static void			calculate_b_price_inv(t_weight **price_b, int position, t_stack **b)
{
	int				stack_len;

	stack_len = stack_len_calc(b);
	if (position > stack_len - position)
	{
		(*price_b)->rb = 0;
		(*price_b)->rrb = stack_len - position;
	}
	else
	{
		(*price_b)->rrb = 0;
		(*price_b)->rb = position;
	}
}

static void			closest_superior_pos(t_weight **price_b, int data, t_stack **b)
{
	t_stack			*temp;
	int				current_pos;
	int				save_pos;
	long			distance;

	temp = *b;
	distance = LONG_MIN;
	current_pos = 1;
	save_pos = 1;
	while (temp)
	{
		if (temp->data > data && data - temp->data > distance)
		{
			distance = data - temp->data;
			save_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	calculate_b_price_inv(price_b, save_pos, b);
}

void				less_costly_b(t_weight *price_b, int data, t_stack **b)
{
	t_stack			*temp;
	int				current_pos;
	int				save_pos;
	long			distance;

	temp = *b;
	distance = LONG_MAX;
	current_pos = 1;
	save_pos = 1;
	while (temp)
	{
		if (temp->data < data && data - temp->data < distance)
		{
			distance = data - temp->data;
			save_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	if (distance == LONG_MAX)
		closest_superior_pos(&price_b, data, b);
	else
		calculate_b_price(&price_b, save_pos, b);
	price_b->total = price_b->ra + price_b->rra + price_b->rb + price_b->rrb;
}