/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 05:27:05 by mrychkov          #+#    #+#             */
/*   Updated: 2018/03/09 05:27:08 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				init_args(t_args *args)
{
	args->debug = 0;
	args->colors = 0;
	args->print = 1;
	args->checker = 0;
	args->total = 0;
	args->num = 0;
	args->ops = 0;
}
