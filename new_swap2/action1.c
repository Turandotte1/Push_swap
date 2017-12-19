#include "../includes/push_swap.h"

void	sa(t_lst *l)
{
	t_elem	*tmp;
	int		copy;
	t_act	act;

	tmp = (l->a)->tail;
	act.name = NULL;
	copy = 0;
	if ((l->a)->length <= 1)
		return ;
	else
	{
		act.name = ft_strdup("sa");
		copy = NB(tmp)->n;
		NB(tmp)->n = NB(tmp->prev)->n;
		NB(tmp->prev)->n = copy;
		ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
	}
}

void	sb(t_lst *l)
{
	t_elem	*tmp;
	int		copy;
	t_act	act;

	tmp = (l->b)->tail;
	act.name = NULL;
	copy = 0;
	if ((l->b)->length <= 1)
		return ;
	else
	{
		act.name = ft_strdup("sb");
		copy = NB(tmp)->n;
		NB(tmp)->n = NB(tmp->prev)->n;
		NB(tmp->prev)->n = copy;
		ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
	}
}

void	ss(t_lst *l)
{
	t_act	act;
	int		act_sa;
	int		act_sb;

	act.name = NULL;
	act_sa = 0;
	act_sb = 0;
	if ((l->a)->length > 1)
		act_sa = 1;
	if ((l->b)->length > 1)
		act_sb = 1;
	if (act_sa != 0 || act_sb != 0)
		act.name = ft_strdup("ss");
	else
		return ;
	sa(l);
	sb(l);
	if (act_sa == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	if (act_sb == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	pa_src(t_dbllist *lst)
{
	if (lst->length == 1)
	{
		lst->tail = NULL;
		lst->head = NULL;
	}
	else
	{
		lst->tail = lst->tail->prev;
		lst->tail->next = NULL;
	}
	lst->length--;
}

void	pa_dst(t_dbllist *lst, t_elem *to_move)
{
	if (lst->length >= 1)
	{
		lst->tail->next = to_move;
		to_move->prev = lst->tail;
		lst->tail = to_move;
	}
	else
	{
		to_move->prev = NULL;
		lst->tail = to_move;
		lst->head = to_move;
	}
	lst->length++;
}

void		pa(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = (l->b)->tail;
	act.name = ft_strdup("pa");
	pa_src(l->b);
	pa_dst(l->a, to_move);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void		pb(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = (l->a)->tail;
	act.name = ft_strdup("pb");
	pa_src(l->a);
	pa_dst(l->b, to_move);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	ra(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = NULL;
	act.name = NULL;
	if ((l->a)->length == 0)
		return ;
	act.name = ft_strdup("ra");
	to_move = (l->a)->tail;
	if ((l->a)->length > 1)
	{
		(l->a)->tail = (l->a)->tail->prev;
		(l->a)->tail->next = NULL;
		(l->a)->head->prev = to_move;
		to_move->next = (l->a)->head;
		(l->a)->head = to_move;
		to_move->prev = NULL;
	}
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rb(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = NULL;
	act.name = NULL;
	if ((l->b)->length == 0)
		return ;
	act.name = ft_strdup("rb");
	to_move = (l->b)->tail;
	if ((l->b)->length > 1)
	{
		(l->b)->tail = (l->b)->tail->prev;
		(l->b)->tail->next = NULL;
		(l->b)->head->prev = to_move;
		to_move->next = (l->b)->head;
		(l->b)->head = to_move;
		to_move->prev = NULL;
	}
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rr(t_lst *l)
{
	t_act	act;
	int		act_ra;
	int		act_rb;

	act.name = NULL;
	act_ra = 0;
	act_rb = 0;
	if ((l->a)->length >= 1)
		act_ra = 1;
	if ((l->b)->length >= 1)
		act_rb = 1;
	if (act_ra != 0 || act_rb != 0)
		act.name = ft_strdup("rr");
	ra(l);
	rb(l);
	if (act_ra == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	if (act_rb == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rra(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = NULL;
	act.name = NULL;
	if ((l->a)->length == 0)
		return ;
	act.name = ft_strdup("rra");
	to_move = (l->a)->head;
	if ((l->a)->length > 1)
	{
		(l->a)->head = (l->a)->head->next;
		(l->a)->head->prev = NULL;
		(l->a)->tail->next = to_move;
		to_move->prev = (l->a)->tail;
		(l->a)->tail = to_move;
		to_move->next = NULL;
	}
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rrb(t_lst *l)
{
	t_elem	*to_move;
	t_act	act;

	to_move = NULL;
	act.name = NULL;
	if ((l->b)->length == 0)
		return ;
	act.name = ft_strdup("rrb");
	to_move = (l->b)->head;
	if ((l->b)->length > 1)
	{
		(l->b)->head = (l->b)->head->next;
		(l->b)->head->prev = NULL;
		(l->b)->tail->next = to_move;
		to_move->prev = (l->b)->tail;
		(l->b)->tail = to_move;
		to_move->next = NULL;
	}
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}

void	rrr(t_lst *l)
{
	t_act	act;
	int		act_rra;
	int		act_rrb;

	act.name = NULL;
	act_rra = 0;
	act_rrb = 0;
	if ((l->a)->length >= 1)
		act_rra = 1;
	if ((l->b)->length >= 1)
		act_rrb = 1;
	if (act_rra != 0 || act_rrb != 0)
		act.name = ft_strdup("rrr");
	rra(l);
	rrb(l);
	if (act_rra == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	if (act_rrb == 1)
		del_and_free_actions(&l->actions, (l->actions)->tail);
	ft_lstdbladd_head(l->actions, &act, sizeof(t_act));
}
