#include "push_swap.h"

int 				check_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
		{
			if (str[i + 1] && ft_isdigit(str[i + 1]))
				i++;
			else
				return (0);
		}
		else if (!(ft_isdigit(str[i])))
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
	if (str[0] == '-' && str[1])
	{
		while (str[i])
		{
			if (!(ft_strchr(OPTIONS, str[i])))
				return (0);
			save_args(str[i], args);
			i++;
		}
		return (1);
	}
	return (0);
}

void			save_args(char args, t_args *as)
{
	if (args == 'i')
		as->info = 1;
	else if (args == 'n')
		as->num = 1;
	else if (args == 'v')
		as->debug = 1;
}

int				check_length(char *str)
{
	if (INT_MIN > ft_atoi_max(str) || ft_atoi_max(str) > INT_MAX)
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