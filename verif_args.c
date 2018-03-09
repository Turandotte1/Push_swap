/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 05:28:59 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/09 05:30:02 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					init_stack_a(t_stack **a, char *av)
{
	int				index;

	index = 0;
	while (av[index])
	{
		while (av[index] == ' ')
			index++;
		if (ft_atoi_max(&av[index]) > INT_MAX
				|| ft_atoi_max(&av[index]) < INT_MIN
				|| (!ft_atoi_max(&av[index])
					&& !ft_full_char(&av[index], '0')))
			return (0);
		stack_fill(a, ft_atoi_max(&av[index]));
		while (av[index] && av[index] != ' ')
			index++;
		while (av[index] && av[index] == ' ')
			index++;
	}
	return (!check_duplicates(a) ? 0 : 1);
}

int					check_duplicates(t_stack **a)
{
	int				temp_index;
	int				current_index;
	t_stack			*temp;
	t_stack			*current;

	current_index = 1;
	current = *a;
	while (current)
	{
		temp = *a;
		temp_index = 1;
		while (temp->next)
		{
			if (current_index != temp_index && temp->data == current->data)
				return (0);
			temp_index++;
			temp = temp->next;
		}
		current = current->next;
		current_index++;
	}
	return (1);
}

void				stack_fill(t_stack **head, int data)
{
	t_stack			*new;

	if (head == NULL)
		return ;
	if (*head == NULL)
	{
		*head = ft_create_elem(data);
		return ;
	}
	new = *head;
	while (new->next != NULL)
		new = new->next;
	new->next = ft_create_elem(data);
}

static int			check_str(char *str)
{
	int				i;
	int				size;
	int				check;

	check = 0;
	i = 0;
	size = ft_strlen(str);
	if (size == 0)
		return (0);
	while (i < size)
	{
		if (str[i] != '+' && str[i] != '-' && str[i] != ' ' &&
				!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (ft_isdigit(str[i]))
			check++;
		i++;
	}
	return ((check) ? 1 : 0);
}

int					check_args(int ac, char **av, int index)
{
	int				cur_index;

	while (index < ac)
	{
		if (!check_str(av[index]))
			return (0);
		cur_index = 1;
		while (cur_index < ac)
		{
			if (index == cur_index)
				cur_index++;
			if (index < ac - 1 && !ft_strcmp(av[index], av[cur_index]))
				return (0);
			cur_index++;
		}
		index++;
	}
	return (1);
}
