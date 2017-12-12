#include "push_swap.h"



void			small_len(t_stack **a, t_stack **b, t_list **instruct)
{
	if (a && (*a)->next)
	{
		if ((*a)->data > (*a)->next->data)
		{
			s_swap(*a, NULL);
			stock_instruct(instruct, "sa");
		}
	}
	if (b && (*b)->next)
	{
		if ((*b)->data < (*b)->next->data)
		{
			s_swap(NULL, *b);
			stock_instruct(instruct, "sb");
		}
	}
	return ;
}

int				sorts_calc(t_stack *a, int pivot, int size)
{	
	int 		nb;

	nb = 0;
	while (a)
	{
		if (a->data < pivot)
			nb++;
		a = a->next;
		size = 0;
	}
	return (nb);
}

int 			backwards_sorts_calc(t_stack *a, int pivot, int size)
{
	int 		nb;

	nb = 0;
	while (a)
	{
		if (a->data > pivot)
			nb++;
		a = a->next;
		size = 0;
	}
	return (nb);
}

t_stack			*create_link(int data)
{
	t_stack		*new_link;

	if (!(new_link = (t_stack *)malloc(sizeof(new_link))))
		ft_malloc_error(__LINE__, __FILE__);
	new_link->data = data;
//	new_link->next = NULL;
	return (new_link);
}