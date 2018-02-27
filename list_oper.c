# include "push_swap.h"

void				delete_ops(t_double **stack)
{
	t_node			*temp;

	temp = (*stack)->head;
	while (temp)
	{
		ft_strdel(&(ACTIONS(temp)->name));
		ACTIONS(temp)->name = NULL;
		temp = temp->next;
	}
	(*stack)->tail = NULL;
	(*stack)->head = NULL;
}

static void			del_lst_one(t_double **stack, t_node *rm)
{
	ft_strdel(&(ACTIONS(rm)->name));
	ft_doublelink_del(stack);
	*stack = ft_doublelink_creat();
	(*stack)->length = 0;
}

static void			del_lst_next_null(t_double **stack, t_node *rm)
{
	ft_strdel(&(ACTIONS(rm)->name));
	(*stack)->tail = rm->prev;
	(*stack)->tail->next = NULL;
}

static void			del_lst_prev_null(t_double **stack, t_node *rm)
{
	ft_strdel(&(ACTIONS(rm)->name));
	(*stack)->head = rm->next;
	(*stack)->head->prev = NULL;
}

void				free_ops(t_double **stack, t_node *rm)
{
	if (rm == NULL)
		return ;
	if ((*stack)->length == 1)
	{
		del_lst_one(stack, rm);
		return ;
	}
	else if (rm->next == NULL)
		del_lst_next_null(stack, rm);
	else if (rm->prev == NULL)
		del_lst_prev_null(stack, rm);
	else
	{
		ft_strdel(&(ACTIONS(rm)->name));
		rm->next->prev = rm->prev;
		rm->prev->next = rm->next;
	}
	free(rm->content);
	free(rm);
	(*stack)->length--;
}
