#include "push_swap.h"

int				length_check(char **av)
{
	int			i;
	intmax_t	num;

	i = 0;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_errors_managment());
		i++;
	}
	return (1);
}

int				duplicate_check(char **av)
{
	int 		i;
	int 		j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!(ft_strcmp(av[i], av[j])))
				return (ft_errors_managment());
			j++;
		}
		i++;
	}
	return (1);
}

int 			args_advanced_check(char *argument, t_args **opt)
{
	int 		i;

	i = (argument[0] == '-' || argument[0] == '+' ? 1 : 0);
	if (ft_isdigit(arg[i]))
	{
		if ((argument[i] == '0' && argument[i + 1] != '\0') ||
			(argument[0] == '-' && argument[1] == '0'))
			return (0);
		while (argument[++i])
			if (!(ft_isdigit(argument[i])))
				return (0);
	}
//	else if (opt && ft_strcmp(arg, "-v") == 0)
//		(*opt)->stack_refresh = true;
//	else if (opt && ft_strcmp(arg, "-s") == 0)
//		(*opt)->display_commands = true;
	else
		return (0);
	return (1);
}

int				arguments_init_check(char **tab, t_args **opt)
{
	int			i;
	int			flag;

	i = 0;
	flag = 0;
	while (tab[i])
	{
		if (!(args_advanced_check(tab[i], opt)))
			return (ft_errors_managment());
		if (flag == 0)
		{
			if ((tab[i][0] == '-' && ft_isdigit(array[i][1]) 
				|| (ft_isdigit(array[i][0]))))
				flag = 1;
		}
		i++;
	}
	if (flag == 0)
		ft_errors_managment();
	return (flag);
}

char			**tab_maker(int ac, char **av)
{
	int			i;
	char		**tab;

	i = 0;
	if (ac == 2)
		return (ft_strsplit(av[1], ' '));
	else
	{
		if (!(tab = malloc(sizeof(tab) * ac)))
			return (ft_malloc_error(__FILE__,__LINE__));
		while (av[i + 1])
		{
			if (!(tab[i] = ft_strdup(av[i + 1])))
				return (NULL);
			i++;
		}
		tab[i] = NULL;
		return (tab);
	}
}
