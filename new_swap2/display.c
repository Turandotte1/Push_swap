void			showlsthead(t_dbllist *list)
{
	t_elem	*tmp;

	tmp = list->head;
	while (tmp != NULL)
	{
		ft_putnbr(NB(tmp)->n);
		if (tmp->next != NULL)
			write(1, " ", 1);
		tmp = tmp->next;
	}
}

static	void	get_color(t_elem *tmp)
{
	if (ft_strequ("sa", ACTIONS(tmp)->name))
		sa_color();
	else if (ft_strequ("sb", ACTIONS(tmp)->name))
		sb_color();
	else if (ft_strequ("ss", ACTIONS(tmp)->name))
		ss_color();
	else if (ft_strequ("pa", ACTIONS(tmp)->name))
		pa_color();
	else if (ft_strequ("pb", ACTIONS(tmp)->name))
		pb_color();
	else if (ft_strequ("ra", ACTIONS(tmp)->name))
		ra_color();
	else if (ft_strequ("rb", ACTIONS(tmp)->name))
		rb_color();
	else if (ft_strequ("rr", ACTIONS(tmp)->name))
		rr_color();
	else if (ft_strequ("rra", ACTIONS(tmp)->name))
		rra_color();
	else if (ft_strequ("rrb", ACTIONS(tmp)->name))
		rrb_color();
	else if (ft_strequ("rrr", ACTIONS(tmp)->name))
		rrr_color();
}

void			show_actions(t_dbllist *actions, t_options *options)
{
	t_elem	*tmp;

	tmp = actions->tail;
	while (tmp != NULL)
	{
		if (tmp->prev == NULL && options->c == 1)
			get_color(tmp);
		else
			ft_putstr(ACTIONS(tmp)->name);
		if (tmp->prev != NULL)
		{
			write(1, " ", 1);
			tmp = tmp->prev;
		}
		else
		{
			ft_printf("\n");
			break ;
		}
	}
}

void			show_piles(t_lst *l, char *actions)
{
	if (actions[0] != '\0')
		ft_printf("\nPiles after %s action :", actions);
	else
		ft_printf("\nPiles :");
	ft_putstr("\na : ");
	showlsthead(l->a);
	ft_putstr("\nb : ");
	showlsthead(l->b);
	ft_putstr("\n");
}

void			display(t_lst *l, t_options *options, int tri)
{
	if ((l->actions)->head == NULL)
	{
		ft_putstr("\nList of actions executed : No action executed\n");
	}
	else
	{
		ft_putstr("\nList of actions executed :\n");
		show_actions((l->actions), options);
	}
	if (options->l == 1)
		show_piles(l, "");
	if (options->i == 1)
		which_tri(tri);
	if (options->n == 1)
		ft_printf("\nNumber of executed actions : %d\n", l->actions->length);
}

void			which_tri(int tri)
{
	if (tri == 1)
		ft_printf("\nSorting method used : Basic Swap\n");
	else if (tri == 2)
		ft_printf("\nSorting method used : Selection Sort\n");
	else if (tri == 3)
		ft_printf("\nSorting method used : Merge Sort\n");
	else if (tri == 4)
		ft_printf("\nSorting method used : Just one inversion\n");
}