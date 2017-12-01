# include "push_swap.h"

static void		array_swap(int *array, int a, int b)
{
	int 		temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

static void		array_quick_sort(int *array, int start, int end)
{
	int 		left;
	int 		right;
	int 		pivot;

	left = start - 1;
	right = end + 1;
	pivot = array[start];
	if (start >= end)
		return ;
	while (1)
	{
		while (array[--right] > pivot)
		{
		}
		while (array[++left] < pivot)
		{
		}
		if (left < right)
			array_swap(array, left, right);
		else
			break ;
	}
	array_quick_sort(array, start, right);
	array_quick_sort(array, right + 1, end);
}

static int		*get_array(t_stack *stack, int size)
{
	int 		*array;
	int 		i;

	i = 0;
	if (!(array = malloc(sizeof(array) * size)))
		ft_malloc_error(__LINE__, __FILE__);
	while (i < size)
	{
		array[i] = stack->data;
		stack = stack->next;
		i++;
	}
	return (array);
}

int				pivot_found(t_stack *stack, int size)
{
	int 		pivot;
	int 		*array;

	array = get_array(stack, size);
	array_quick_sort(array, 0, size);
	pivot = array[size >> 1];
	free(array);
	return (pivot);
}