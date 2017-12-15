#include "push_swap.h"

int	gnl_loop(t_stack **a, t_stack **b, t_options *opt, int *inst_nb)
{
	int		gnl;
	char	*command;

	while ((gnl = get_next_line(0, &command)))
	{
		if (exec_instruction(command, a, b, NULL) == false)
		{
			ft_strdel(&command);
			return (ERROR);
		}
		(*inst_nb)++;
		if (opt->clear_screen == true)
			ft_cls();
		if (opt->stack_refresh == true)
			stack_print(*a, *b);
		if (opt->display_commands == true)
			ft_printf("Instructions executed :\t{GREEN}%d{EOC}\n\n", *inst_nb);
		ft_strdel(&command);
	}
	return (gnl);
}

int	instructions_parsing(t_stack **a, t_stack **b, t_options *opt, int *inst_nb)
{
	*inst_nb = 0;
	if (opt->clear_screen == true)
	{
		ft_cls();
	}
	if (opt->stack_refresh == true)
	{
		stack_print(*a, *b);
	}
	ft_printf("Enter instructions :\n");
	return (gnl_loop(a, b, opt, inst_nb));
}