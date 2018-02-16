void			push_swap_error(int key, intmax_t i, char *str)
{
	if (key == 1)
		ft_printf("Error: invalid argument -%s-\nI don't know how to deal with it:(\n", str);
	else if (key == 2)
		ft_printf("Error: argument -%jd- is too big for an int\nI don't know how to deal with it:(\n", i);
	else if (key == 3)
		ft_printf("Error: there are duplicates of -%jd- in the input\nI don't know how to deal with it:(\n", i);
	ft_printf("Usage: ./push_swap 2 4 9 42...\nPlease enter at least one integer or verify the input\n");
	exit(EXIT_FAILURE);
}