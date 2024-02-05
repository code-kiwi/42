/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:19:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/02/05 14:18:59 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	all_mins_a_to_b(t_ps_data *data)
{
	t_stack	*a;
	size_t	min_index;

	a = data->stack_a;
	while (a->size > 3 && !(data->is_sorted_stack(data, STACK_A_LETTER)))
	{
		min_index = get_min_index(a);
		if (min_index <= a->size / 2)
			multiple_ra(data, min_index);
		else
			multiple_rra(data, a->size - min_index);
		if (!(data->is_sorted_stack(data, STACK_A_LETTER)))
			data->pb(data, true);
	}
	if (a->size == 3)
		sort_size_three(data);
}

static void	all_b_to_a(t_ps_data *data)
{
	while ((data->stack_b)->size > 0)
		data->pa(data, true);
}

void	sort1(t_ps_data *data)
{
	if (
		data == NULL || data->stack_a == NULL || data->stack_b == NULL
		|| data->is_sorted_stack(data, STACK_A_LETTER)
	)
		return ;
	all_mins_a_to_b(data);
	all_b_to_a(data);
	return ;
}