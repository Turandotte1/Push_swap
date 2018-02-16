#include "../includes/push_swap.h"

/*static	int		findn(int n, t_dbllist *a)
{
	t_elem	*tmp;

	tmp = a->head;
	while (tmp != NULL)
	{
		if (NB(tmp)->check == 0 && n == NB(tmp)->n)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}*/

/*int				verif_dup(t_dbllist **a)
{
	t_elem	*tmp;

	tmp = (*a)->head;
	while (tmp != NULL)
	{
		NB(tmp)->check = 1;
		if (findn(NB(tmp)->n, *a) == 1)
			return (0);
		NB(tmp)->check = 0;
		tmp = tmp->next;
	}
	return (1);
}*/

/*int				verif_limits(char *av)
{
	if (INT_MIN > ft_atoi_intmax(av) || ft_atoi_intmax(av) > INT_MAX)
		return (0);
	return (1);
}*/

//int				verif_options(char *av, t_options *options)
//{
//	int			i;
//
/*	i = 1;
	if (av[0] == '-' && av[1])
	{
		while (av[i])
		{
			if (!(ft_strchr(OPTIONS, av[i])))
				return (0);
			save_options(av[i], options);
			i++;
		}
		return (1);
	}
	return (0);
}*/