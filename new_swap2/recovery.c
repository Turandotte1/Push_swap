static	void	save_nb(t_dbllist **a, t_nb *snb, char **av, int i)
{
	snb->n = ft_atoi(av[i]);
	ft_lstdbladd_head(*a, snb, sizeof(t_nb));
}

int				recover_and_verif(t_dbllist **a, t_options *options, char **av)
{
	t_nb		snb;
	int			i;
	int			no_record;

	ini_tnb(&snb);
	i = 1;
	no_record = 0;
	while (av[i])
	{
		if (!(verif_digit(av[i])))
		{
			if (i == 1 && verif_options(av[1], options))
				no_record++;
			else
				return (0);
		}
		if (!(verif_limits(av[i])))
			return (0);
		if (no_record == 0)
			save_nb(a, &snb, av, i);
		i++;
		no_record = 0;
	}
	return (!(verif_dup(a))) ? 0 : 1;
}

int				recover(t_lst *l, t_options *options, char **av)
{
	if (!(recover_and_verif(&l->a, options, av)))
	{
		ft_lstdbldel(&l->a);
		free(l->a);
		ft_lstdbldel(&l->b);
		free(l->b);
		ft_lstactionsdel(&l->actions);
		free(l->actions);
		return (0);
	}
	else
		return (1);
}