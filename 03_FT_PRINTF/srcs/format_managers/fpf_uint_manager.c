/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_uint_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 17:05:15 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fpf_uint_manager(va_list args, t_input_format *input)
{
	unsigned int	nb;

	if (args == NULL || input == NULL)
		return (NULL);
	nb = va_arg(args, unsigned int);
	return (ft_ltoa(nb));
}