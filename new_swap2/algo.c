t_elem	*find_min(t_dbllist **pile)
{
	t_elem	*tmp;
	t_elem	*min;

	tmp = NULL;
	min = NULL;
	if ((*pile)->length < 1)
		return (NULL);
	tmp = (*pile)->head;
	min = (*pile)->head;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && NB(min)->n > NB(tmp->next)->n)
			min = tmp->next;
		tmp = tmp->next;
	}
	return (min);
}

int		which_side(t_dbllist **pile, t_elem *elem, int *count)
{
	t_elem	*tmp_head;
	t_elem	*tmp_tail;
	int		count_head;
	int		count_tail;

	tmp_head = (*pile)->head;
	tmp_tail = (*pile)->tail;
	count_head = 0;
	count_tail = 0;
	while (tmp_head != NULL && tmp_head != elem)
	{
		count_head++;
		tmp_head = tmp_head->next;
	}
	count_tail = (*pile)->length - 1 - count_head;
	if (count_head >= count_tail)
		*count = count_tail;
	else
		*count = count_head;
	return (count_head >= count_tail) ? 0 : 1;
}

void	tri_simple(t_lst *l, t_options *options, int *tri)
{
	while ((l->a)->length > 0)
	{
		more_effective_moving(l, find_min(&l->a), options);
		pb(l);
		if (options->v == 1)
			show_piles(l, "pb");
	}
	while ((l->b)->length > 0)
	{
		pa(l);
		if (options->v == 1)
			show_piles(l, "pa");
	}
	*tri = 2;
}

void		separate_lst(t_lst *l, int pivot, t_options *options)
{
	t_elem	*tmp;
	int		count;

	(void)pivot;
	(void)options;
	tmp = (l->a)->tail;
	count = (l->a)->length;
	while (count > 0)
	{
		if (NB(tmp)->n < pivot)
			pb(l);
		else
			ra(l);
		count--;
		tmp = (l->a)->tail;
	}
}

int		define_pivot(t_lst *l)
{
	lst_pivot(l);
	return (which_pivot(l, 1));
}

void			tri_quicksort(t_lst *l, t_options *options, int *tri)
{
	int		value_pivot;

	(void)options;
	value_pivot = define_pivot(l);
	separate_lst(l, value_pivot, options);
	if (!(is_sorted(l->a)))
		tri_a(l, options);
	if (!(is_reversed(l->b)))
		tri_b(l, options);
	while (l->b->length > 0)
	{
		pa(l);
		if (options->v == 1)
			show_piles(l, "pa");
	}
	*tri = 3;
}

void	pivot_gap(t_pivot *pivot)
{
	if (pivot->upper >= pivot->lower)
		pivot->gap = pivot->upper - pivot->lower;
	else
		pivot->gap = pivot->lower - pivot->upper;
}

void	pivot_upper(t_lst *l, t_pivot *pivot)
{
	if ((int)(l->a)->length > pivot->lower)
		pivot->upper = (int)(l->a)->length - pivot->lower - 1;
	else
		pivot->upper = pivot->lower - (int)(l->a)->length - 1;
}

void			lst_pivot(t_lst *l)
{
	t_elem		*tmp;
	int			count;
	t_pivot		pivot;

	tmp = (l->a)->head;
	count = 0;
	ini_pivot(&pivot);
	pivot.pos = (l->a)->head;
	while (pivot.pos != NULL)
	{
		while (tmp != NULL)
		{
			if (tmp != pivot.pos && NB(tmp)->n < NB(pivot.pos)->n)
				pivot.lower++;
			tmp = tmp->next;
		}
		pivot_upper(l, &pivot);
		pivot_gap(&pivot);
		ft_lstdbladd(l->piv, &pivot, sizeof(t_pivot));
		pivot.pos = pivot.pos->next;
		pivot.lower = 0;
		pivot.upper = 0;
		pivot.gap = 0;
		tmp = (l->a)->head;
	}
}

int				which_pivot(t_lst *l, int value)
{
	t_elem	*tmp;
	t_elem	*pivot;

	tmp = l->piv->head;
	pivot = l->piv->head;
	while (tmp != NULL)
	{
		if (PIVOT(pivot)->gap > PIVOT(tmp)->gap)
			pivot = tmp;
		tmp = tmp->next;
	}
	if (value == 1)
		return (NB(PIVOT(pivot)->pos)->n);
	else
		return (PIVOT(pivot)->lower);
}

t_elem	*find_max(t_dbllist **pile)
{
	t_elem	*tmp;
	t_elem	*max;

	tmp = NULL;
	max = NULL;
	if ((*pile)->length < 1)
		return (NULL);
	tmp = (*pile)->head;
	max = (*pile)->head;
	while (tmp != NULL)
	{
		if (NB(max)->n < NB(tmp)->n)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void			tri_a(t_lst *l, t_options *options)
{
	int		count;

	count = 0;
	while ((l->a)->length > 0)
	{
		more_effective_moving(l, find_min(&l->a), options);
		pb(l);
		count++;
		if (options->v == 1)
			show_piles(l, "pb");
	}
	while (count > 0)
	{
		pa(l);
		if (options->v == 1)
			show_piles(l, "pa");
		count--;
	}
}

void			tri_b(t_lst *l, t_options *options)
{
	int		count;

	count = 0;
	while ((l->b)->length > 0)
	{
		more_effective_moving_b(l, find_max(&l->b), options);
		pa(l);
		count++;
		if (options->v == 1)
			show_piles(l, "pa");
	}
	while (count > 0)
	{
		pb(l);
		if (options->v == 1)
			show_piles(l, "pb");
		count--;
	}
}

void	more_effective_moving_b(t_lst *l, t_elem *elem, t_options *options)
{
	int		count;

	count = 0;
	if (which_side(&l->b, elem, &count) == 0)
	{
		while (count > 0)
		{
			rb(l);
			if (options->v == 1)
				show_piles(l, "rb");
			count--;
		}
	}
	else
	{
		count++;
		while (count > 0)
		{
			rrb(l);
			if (options->v == 1)
				show_piles(l, "rrb");
			count--;
		}
	}
}




