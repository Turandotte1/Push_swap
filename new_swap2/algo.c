


t_elem	*find_max(t_dbllist **pile)
{
	t_elem	*tmp;
	t_elem	*max;

	tmp = NULL;
	max = NULL;
	if ((*pile)->length < 1)
		return (NULL);
	tmp = (*pile)->head;
	max = (*pile)->head;
	while (tmp != NULL)
	{
		if (NB(max)->n < NB(tmp)->n)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}






