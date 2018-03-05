/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:31:20 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/05 07:23:04 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			print_a_b(t_stack **temp_a, t_stack **temp_b,
									t_args *args)
{
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|           |             |\n");
	ft_printf("|%5d      |    %4d     |\n", (*temp_a)->data,
		(*temp_b)->data);
	ft_printf("|");
	if (args->colors)
		write(1, GREEN, ft_strlen(GREEN));
	ft_printf(" _________ ");
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|");
	if (args->colors)
		write(1, GREEN, ft_strlen(GREEN));
	ft_printf(" ___________ ");
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|\n");
	if (args->colors)
		write(1, END, ft_strlen(END));
	*temp_a = (*temp_a)->next;
	*temp_b = (*temp_b)->next;
}

static void			print_a(t_stack **temp_a, t_args *args)
{
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|           |             |\n");
	ft_printf("|%5d      |             |\n", (*temp_a)->data);
	ft_printf("|");
	if (args->colors)
		write(1, GREEN, ft_strlen(GREEN));
	ft_printf(" _________ ");
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|");
	if (args->colors)
		write(1, GREEN, ft_strlen(GREEN));
	ft_printf(" ___________ ");
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|\n");
	if (args->colors)
		write(1, END, ft_strlen(END));
	*temp_a = (*temp_a)->next;
}

static void			print_b(t_stack **temp_b, t_args *args)
{
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|           |             |\n");
	ft_printf("|           |    %4d     |\n", (*temp_b)->data);
	ft_printf("|");
	if (args->colors)
		write(1, GREEN, ft_strlen(GREEN));
	ft_printf(" _________ ");
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|");
	if (args->colors)
		write(1, GREEN, ft_strlen(GREEN));
	ft_printf(" ___________ ");
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|\n");
	if (args->colors)
		write(1, END, ft_strlen(END));
	*temp_b = (*temp_b)->next;
}

void				debug_opt(t_stack **a, t_stack **b, t_args *args)
{
	t_stack			*temp_a;
	t_stack			*temp_b;

	temp_a = *a;
	temp_b = *b;
	if (args->colors)
		write(1, GREEN, ft_strlen(GREEN));
	ft_printf("\n===========================\n");
	if (args->colors)
		write(1, BROWN, ft_strlen(BROWN));
	ft_printf("|    A    STACK     B     |\n");
	if (args->colors)
		write(1, GREEN, ft_strlen(GREEN));
	ft_printf("===========================\n");
	while (temp_a || temp_b)
	{
		if (temp_a && temp_b)
			print_a_b(&temp_a, &temp_b, args);
		if (temp_a && !temp_b)
			print_a(&temp_a, args);
		if (!temp_a && temp_b)
			print_b(&temp_b, args);
	}
	ft_printf("\n");
}

void				print_info(t_args *args)
{
	args->execution_time = ((double)(args->end - args->start)) / CLOCKS_PER_SEC;
	if (args->colors)
		write(1, CYAN, ft_strlen(CYAN));
	printf("\nI've executed this sort in %.2f sec\n", args->execution_time);
	ft_printf("I've managed doing it in %d operations\n", args->ops);
	if (args->colors)
		write(1, END, ft_strlen(END));
}
