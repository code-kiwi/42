/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_hexa_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 17:03:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fpf_hexa_manager(va_list args, t_input_format *input)
{
	unsigned int	nb;
	char			*res;

	if (args == NULL || input == NULL)
		return (NULL);
	nb = va_arg(args, unsigned int);
	if (input->format == 'x')
		res = ft_ltoa_base(nb, "0123456789abcdef");
	else
		res = ft_ltoa_base(nb, "0123456789ABCDEF");
	return (res);
}
