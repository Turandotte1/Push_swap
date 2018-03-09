/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:10:07 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/09 05:36:14 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			compare(int data, t_stack **a)
{
	t_stack			*temp;

	temp = *a;
	while (temp)
	{
		if (data > temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int					find_min(t_stack **a)
{
	int				min;
	t_stack			*temp;

	temp = *a;
	min = 0;
	while (temp)
	{
		if (compare(temp->data, a))
			break ;
		min++;
		temp = temp->next;
	}
	return (min);
}

int					stack_len_calc(t_stack **a)
{
	int				len;
	t_stack			*temp;

	if (!*a)
		return (0);
	len = 1;
	temp = *a;
	while (temp->next)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

void				free_this_shit(t_stack **head)
{
	t_stack			*current;
	t_stack			*remove;

	if (head == NULL)
		return ;
	if (*head == NULL)
		return ;
	current = *head;
	while (current->next)
	{
		remove = current;
		current = current->next;
		free(remove);
	}
	free(current);
	*head = NULL;
}

t_stack				*ft_create_elem(int data)
{
	t_stack			*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (new);
	new->data = data;
	new->next = NULL;
	return (new);
}
