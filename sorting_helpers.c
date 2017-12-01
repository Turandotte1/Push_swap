#include "push_swap.h"

void			stock_instruct(t_list **instruct, char *str)
{
	t_list		*temp;

	temp = *instruct;
	if (*instruct == NULL)
		*instruct = ft_lstnew(str, ft_strlen(str) + 1);
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(str, ft_strlen(str) + 1);
	}
}

void			small_len(t_stack **a, t_stack **b, t_list **instruct)
{
	if (a && *a && (*a)->next)
	{
		if ((*a)->data > (*a)->next->data)
		{
			s_swap(*a);
			stock_instruct(instruct, "sa");
		}
	}
	if (b && *b && (*b)->next)
	{
		if ((*b)->data < (*b)->next->data)
		{
			s_swap(*b);
			stock_instruct(instruct, "sb");
		}
	}
	return ;
}

int				sorts_calc(t_stack **a, int pivot, int size)
{	
	int 		nb;
	t_stack		*p;

	nb = 0;
	p = *a;
	while (size)
	{
		if (p->data < pivot)
			nb++;
		p = p->next;
		size--;
	}
	return (nb);
}

int 			backwards_sorts_calc(t_stack **a, int pivot, int size)
{
	int 		nb;
	t_stack 	*p;

	nb = 0;
	p = *a;
	while (size)
	{
		if (p->data > pivot)
			nb++;
		p = p->next;
		size--;
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