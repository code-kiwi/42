/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:48:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/09 20:47:53 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	Allocates a t_ps_data and set its components values
 *	The stacks A and B are allocated too but empty
 *	NB:	- calls p_data_set_functions in order to initialize function pointers
 *		- if an allocated fails, NULL is returned
 */
t_ps_data	*ps_data_init(void)
{
	t_ps_data	*data;

	data = (t_ps_data *) malloc(sizeof(t_ps_data));
	if (data == NULL)
		return (NULL);
	data->stack_a = stack_init();
	if (data->stack_a == NULL)
	{
		free(data);
		return (NULL);
	}
	data->stack_b = stack_init();
	if (data->stack_b == NULL)
	{
		(data->stack_a)->clear(&(data->stack_a), free);
		free(data);
		return (NULL);
	}
	ps_data_set_functions(data);
	return (data);
}

/*
 *	Sets the function pointers of the given t_ps_data pointer
 */
void	ps_data_set_functions(t_ps_data *data)
{
	if (data == NULL)
		return ;
	data->sa = push_swap_sa;
	data->sb = push_swap_sb;
	data->ss = push_swap_ss;
	data->pa = push_swap_pa;
	data->pb = push_swap_pb;
	data->ra = push_swap_ra;
	data->rb = push_swap_rb;
	data->rr = push_swap_rr;
	data->rra = push_swap_rra;
	data->rrb = push_swap_rrb;
	data->rrr = push_swap_rrr;
	data->push_a = push_swap_push_a;
	data->clear = ps_data_clear;
	data->display = push_swap_display;
}

/*
 *	Clears the given ps_data by freeing its stacks and the data itself
 *	Sets the given pointer to NULL
 */
void	ps_data_clear(t_ps_data **data)
{
	t_stack	*stack;

	if (data == NULL || *data == NULL)
		return ;
	stack = (*data)->stack_a;
	stack->clear(&stack, free);
	stack = (*data)->stack_b;
	stack->clear(&stack, free);
	free(*data);
	*data = NULL;
}

/*
 *	Displays the content of a t_ps_data element
 */
void	push_swap_display(t_ps_data *data)
{
	if (data == NULL)
	{
		ft_printf("ERROR - The given push_swap data is NULL\n");
		return ;
	}
	ft_printf("#####################\n");
	ft_printf("#  PUSH_SWAP DATA:  #\n");
	ft_printf("#####################\n\n");
	ft_printf("STACK_A:\n\t");
	display_int_stack(data->stack_a);
	ft_printf("STACK_B:\n\t");
	display_int_stack(data->stack_b);
	ft_printf("\n###################\n\n");
}

/*
 *	Displays the content of a t_stack element
 */
void	display_int_stack(t_stack *stack)
{
	t_list	*current;

	if (stack == NULL || stack->list == NULL)
	{
		ft_printf("Stack is empty...\n");
		return ;
	}
	current = stack->list;
	ft_printf("- content: ");
	while (current != NULL)
	{
		ft_printf("%+5d", *((int *)(current->content)));
		current = current->next;
		if (current != NULL)
			ft_printf(" | ");
	}
	ft_printf("\n");
}