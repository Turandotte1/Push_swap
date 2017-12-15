#include "push_swap.h"

void	display_usage(void)
{
	ft_putendl("usage: ./checker 1 2 3 4... [-i] [-v] [-c]");
	ft_putendl("[-i]: prints the number of instructions executed.");
	ft_putendl("[-v]: updates the display of the stacks.");
	ft_putendl("[-c]: clears the console after each operation.");
}

int		main(int argc, char *argv[])
{
	int			inst_nb;
	t_stack		*a;
	t_stack		*b;
	t_options	*o;

	a = NULL;
	b = NULL;
	o = NULL;
	inst_nb = 0;
	if (argc > 1)
	{
		if ((args_parse(argv, argc, &a, &o) == false) ||
			(instructions_parsing(&a, &b, o, &inst_nb) == ERROR))
		{
			handle_error(a, b, NULL, o);
		}
		print_result(a, b, o, inst_nb);
		freedom(a, b, NULL, o);
	}
	else
	{
		display_usage();
	}
	return (EXIT_SUCCESS);
}