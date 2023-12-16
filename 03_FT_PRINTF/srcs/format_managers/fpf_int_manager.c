/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_int_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:19:25 by mhotting          #+#    #+#             */
/*   Updated: 2023/12/16 16:15:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fpf_int_formatter_plus_space(char *str, t_input_format *input)
{
	char	*res;

	if (str == NULL || input == NULL)
		return (NULL);
	res = str;
	if (input->plus)
	{
		res = ft_strjoin("+", res);
		if (res == NULL)
			return (NULL);
	}
	else if (input->space)
	{
		res = ft_strjoin(" ", res);
		if (res == NULL)
			return (NULL);
	}
	return (res);
}

static void	fpf_int_formatter_negative(char *str)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0' && str[i] != '-')
		i++;
	if (str[i] != '-')
		return ;
	while (i >= 1)
	{
		if (str[i - 1] != '0')
			break ;
		str[i - 1] = '-';
		str[i] = '0';
		i--;
	}
}

static char	*fpf_int_formatter(char *str, t_input_format *input, int nb)
{
	char	*temp;
	char	*res;

	if (nb < 0 && input != NULL && input->precision)
		input->precision_val += 1;
	temp = fpf_formatter_precision(str, input, nb);
	if (str == NULL || input == NULL || temp == NULL)
		return (NULL);
	if (nb >= 0)
	{
		res = fpf_int_formatter_plus_space(temp, input);
		if (temp != str && temp != res)
			free(temp);
		if (res == NULL)
			return (NULL);
		temp = res;
	}
	res = fpf_formatter_length(temp, input);
	if (temp != str && temp != res)
		free(temp);
	if (nb < 0)
		fpf_int_formatter_negative(res);
	return (res);
}

char	*fpf_int_manager(va_list args, t_input_format *input)
{
	int		nb;
	char	*temp;
	char	*res;

	if (args == NULL || input == NULL)
		return (NULL);
	nb = va_arg(args, int);
	temp = ft_itoa(nb);
	if (temp == NULL)
		return (NULL);
	res = fpf_int_formatter(temp, input, nb);
	if (temp != res)
		free(temp);
	return (res);
}
