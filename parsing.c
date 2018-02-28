#include "push_swap.h"

int				find_n(int nb, t_double *stack_a)
{
	t_node		*temp;

	temp = stack_a->head;
	while (temp)
	{
		if (NB(temp)->flag == 0 && nb == NB(temp)->nb)
			return (1);
		else
			temp = temp->next;
	}
	return (0);
}

void				save_num(char **av, t_double **a, t_n *n, int i)
{
	n->nb = ft_atoi(av[i]);
	ft_doublelink_add_head(*a, n, sizeof(t_n));
}

int 				input_check(char **av, t_double **a, t_args *args)
{
	int				i;
	int				no;
	t_n				n;

	i = 1;
	no = 0;
	init_n(&n);
	while (av[i])
	{
		if (!(check_digit(av[i])))
		{
			if (i == 1 && opt_browse(av[1], args))
				no++;
			else
				return (0);
		}
		if (!(check_length(av[i])))
			return (0);
		if (no == 0)
			save_num(av, a, &n, i);
		i++;
		no = 0;
	}
	return ((!(check_duplicates(a))) ? 0 : 1);
}

int					get_user_data(char **av, t_pushswap *push_swap, t_args *args)
{
	if (!(input_check(av, &push_swap->stack_a, args)))
	{
		ft_doublelink_del(&push_swap->stack_a);
		free(push_swap->stack_a);
		ft_doublelink_del(&push_swap->stack_b);
		free(push_swap->stack_b);
		delete_ops(&push_swap->stack_op);
		free(push_swap->stack_op);
		return (0);
	}
	return (1);
}
