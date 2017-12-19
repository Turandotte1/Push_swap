#include "../includes/push_swap.h"

void	ini_tnb(t_nb *snb)
{
	snb->n = 0;
	snb->check = 0;
}

void	ini_topt(t_options *sopt)
{
	sopt->n = 0;
	sopt->v = 0;
	sopt->c = 0;
	sopt->l = 0;
	sopt->i = 0;
}

void	ini_lst(t_lst *l)
{
	l->a = ft_lstdblnew();
	l->b = ft_lstdblnew();
	l->actions = ft_lstdblnew();
	l->piv = ft_lstdblnew();
}

void	ini_pivot(t_pivot *pivot)
{
	pivot->pos = NULL;
	pivot->lower = 0;
	pivot->upper = 0;
	pivot->gap = 0;
}

void	ini_lst_empty(t_lst *l)
{
	l->a = NULL;
	l->b = NULL;
	l->actions = NULL;
	l->piv = NULL;
}