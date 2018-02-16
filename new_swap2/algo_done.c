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
