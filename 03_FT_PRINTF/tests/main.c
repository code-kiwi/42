/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:43:08 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/14 12:54:40 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	/*
	int		v1;
	int		v2;
	const char	*format = "%d %u %wyHello%%%%% World %c!  %X   %\n";

	v1 = ft_printf(format, 50, (unsigned int)-1, 'a', -2147483648);
	v2 = printf(format, 50, (unsigned int)-1, 'a', -2147483648);
	printf("V1: %d - V2: %d - LEN: %zu\n", v1, v2, ft_strlen(format));
	*/
	printf("\"%s\"\n", ft_ultoa_base(ULONG_MAX + 124, "012"));
	printf("\"%lu\"\n", ULONG_MAX);

	return (0);
}
