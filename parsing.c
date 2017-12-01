#include "push_swap.h"

static int			check_length(intmax_t *tab, int nb)
{
	int 		i;

	i = 0;
	while (i < nb)
	{
		if (tab[i] > INT_MAX || tab[i] < INT_MIN)
			error_managment(3, tab[i], NULL);
		i++;
	}
	return (42);
}

static int			check_duplicates(intmax_t *tab, int nb)
{
	int			i;
	int 		j;

	i = 0;
	check_length(tab, nb);
	while (i < nb)
	{
		j = i + 1;
		while (j < nb)
		{
			if (tab[i] == tab[j])
				error_managment(4, tab[i], NULL);
			j++;
		}
		i++;
	}
	return (42);
}

static int 			opt_browse(char *str, t_args *info)
{
	if ((ft_strcmp("-s", str)) || (ft_strcmp("--stat", str)))
		info->stat = 1;
	else if ((ft_strcmp("-v", str)) || (ft_strcmp("--debug", str)))
		info->debug = 0;
	else
	{
		ft_printf("Unknown option: %s\n", str);
		error_managment(1, 0, NULL);
	}
	return (42);
}

static int 			validity_check(char *str)
{
	int 			i;

	i = 0;
	while (*(str + i))
	{
		if ((*(str + i)) < '0' && (*(str + i)) > '9' && (!ft_isspace(*(str + i))))
			error_managment(2, 0, str);
		i++;
	}
	return (42);
} 

int					get_user_data(int ac, char **av, t_stack **stack_a, t_args *info)
{
	int 			i;
	int 			j;
	intmax_t 		*tab;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(long long) * ac - 1)))
		ft_malloc_error(__LINE__, __FILE__);
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			opt_browse(av[i], info);
			info->options++;
		}
		else
		{
			validity_check(av[i]);
			tab[j++] = ft_atoi(av[i]);
		}
	}
	check_duplicates(tab, j);
	while (j)
		ft_push(stack_a, tab[--j]);
	return (42);
}