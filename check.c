#include "push_swap.h"

int 				check_digit(char *str)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if (i == 0 && av[i] == '-')
		{
			if (av[i + 1] && ft_isdigit(av[i + 1]))
				i++;
			else
				return (0);
		}
		else if (!(ft_isdigit(av[i])))
			return (0);
		else
			i++;
	}
	return (1);
}

int				opt_browse(char *str, t_args *args)
{
	int			i;

	i = 1;
	if (av[0] == '-' && av[1])
	{
		while (av[i])
		{
			if (!(ft_strchr(ARGS, av[i])))
				return (0);
			save_args(av[i], args);
			i++;
		}
		return (1);
	}
	return (0);
}

void			save_args(char args, t_args *args)
{
	if (args == 'i')
		args->info = 1;
	else if (args == 'n')
		args->num = 1;
	else if (opt == 'v')
		args->debug = 1;
}

int				check_length(char **str)
{
	if (INT_MIN > ft_atoi_max(av) || ft_atoi_max(av) > INT_MAX)
		return (0);
	return (1);
}

int				check_duplicates(t_double **stack_a)
{
	t_node		*temp;

	temp = (*stack_a)->head;
	while (temp)
	{
		NB(temp)->flag = 1;
		if (find_n(NB(temp)->nb, *stack_a) == 1)
			return (0);
		NB(temp)->flag = 0;
		temp = temp->next;
	}
	return (1);
}