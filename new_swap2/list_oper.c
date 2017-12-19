#include "../includes/push_swap.h"

void			ft_lstactionsdel(t_dbllist **list)
{
	t_elem	*tmp;

	tmp = (*list)->head;
	while (tmp != NULL)
	{
		ft_strdel(&(ACTIONS(tmp)->name));
		ACTIONS(tmp)->name = NULL;
		tmp = tmp->next;
	}
	(*list)->tail = NULL;
	(*list)->head = NULL;
}

static	void	del_lst_one(t_dbllist **list, t_elem *to_remove)
{
	ft_strdel(&(ACTIONS(to_remove)->name));
	ft_lstdbldel(list);
	*list = ft_lstdblnew();
	(*list)->length = 0;
}

static	void	del_lst_next_null(t_dbllist **list, t_elem *to_remove)
{
	ft_strdel(&(ACTIONS(to_remove)->name));
	(*list)->tail = to_remove->prev;
	(*list)->tail->next = NULL;
}

static	void	del_lst_prev_null(t_dbllist **list, t_elem *to_remove)
{
	ft_strdel(&(ACTIONS(to_remove)->name));
	(*list)->head = to_remove->next;
	(*list)->head->prev = NULL;
}

void			del_and_free_actions(t_dbllist **list, t_elem *to_remove)
{
	if (to_remove == NULL)
		return ;
	if ((*list)->length == 1)
	{
		del_lst_one(list, to_remove);
		return ;
	}
	else if (to_remove->next == NULL)
		del_lst_next_null(list, to_remove);
	else if (to_remove->prev == NULL)
		del_lst_prev_null(list, to_remove);
	else
	{
		ft_strdel(&(ACTIONS(to_remove)->name));
		to_remove->next->prev = to_remove->prev;
		to_remove->prev->next = to_remove->next;
	}
	free(to_remove->content);
	free(to_remove);
	(*list)->length--;
}
