show_piles = debug_opt;

/*void	algo(t_lst *l, t_options *options)
{
	int		tri;

	tri = 0;
	if (l->a->length > 1)
	{
		while (!(is_sorted(l->a)))
		{
			if ((l->a)->length <= 19)
			{
				if ((l->a)->length == 3 && is_reversed(l->a) == 1)
					be_almost_sorted_2(l, options, &tri);
				else if (!(a_is_almost_sorted(l, options, &tri)))
					tri_simple(l, options, &tri);
			}
			else if (!(a_is_almost_sorted(l, options, &tri)))
				tri_quicksort(l, options, &tri);
		}
	}
	if (l->a->length != 0)
		display(l, options, tri);
}*/

/*int				is_sorted(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->head;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && NB(tmp)->n < NB(tmp->next)->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}*/

/*int				be_almost_sorted_2(t_lst *l, t_options *options, int *tri)
{
	t_elem	*tmp;
	t_elem	*switch_next;
	int		count;

	tmp = (l->a)->head;
	switch_next = NULL;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && NB(tmp)->n > NB(tmp->next)->n)
			count++;
		if (count > 0)
			return (0);
		tmp = tmp->next;
	}
	sa(l);
	if (options->v == 1)
		show_piles(l, "sa");
	rra(l);
	if (options->v == 1)
		show_piles(l, "rra");
	*tri = 1;
	return (1);
}*/

/*int				a_is_almost_sorted(t_lst *l, t_options *options, int *tri)
{
	t_elem	*tmp;
	t_elem	*first;
	t_elem	*second;
	int		count;

	tmp = (l->a)->head;
	first = NULL;
	second = NULL;
	count = 0;
	while (tmp != NULL)
	{
		if (tmp->next != NULL && NB(tmp)->n < NB(tmp->next)->n)
		{
			first = tmp;
			second = tmp->next;
			count++;
		}
		tmp = tmp->next;
	}
	if (count != 1 || !(check_next_second(first, second))
		|| !(check_prev_first(first, second)))
		return (0);
	switch_and_sort(l, second, options);
	*tri = 4;
	return (1);
}*/

/*int		check_next_second(t_elem *first, t_elem *second)
{
	t_elem	*tmp;

	tmp = NULL;
	if (second->next)
		tmp = second->next;
	else
		return (1);
	while (tmp != NULL)
	{
		if (tmp != second && NB(first)->n < NB(tmp)->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

 int		check_prev_first(t_elem *first, t_elem *second)
{
	t_elem	*tmp;

	tmp = NULL;
	if (first->prev)
		tmp = first->prev;
	else
		return (1);
	while (tmp != NULL)
	{
		if (tmp != second && NB(first)->n > NB(tmp)->n)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}*/

/*int		which_side(t_dbllist **pile, t_elem *elem, int *count)
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
}*/

t_elem	*find_min(t_dbllist **pile)
{
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
	while (l->b->length > 0
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