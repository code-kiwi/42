/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:00:38 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/21 11:01:27 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (
		c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v'
	);
}
