/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:49:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/01/09 20:50:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_ps_data	*data;

	data = ps_data_init();
	if (data == NULL)
	{
		ft_printf("ERROR - Data could not be allocated\n");
		return (0);
	}
	ft_printf("WELCOME to push_swap project\n");
	data->clear(&data);
	return (0);
}
