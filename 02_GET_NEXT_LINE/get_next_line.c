/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:03:38 by mhotting          #+#    #+#             */
/*   Updated: 2023/11/20 08:41:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_store(char **res, char **store, int *nl_found)
{
	char	**gnl_split_res;

	if (*store == NULL)
		return (1);
	gnl_split_res = gnl_split(*store, nl_found);
	free(*store);
	*store = NULL;
	if (gnl_split_res == NULL)
	{
		clear_memory(res, store, NULL);
		return (0);
	}
	if (gnl_split_res[0] != NULL)
		*res = gnl_split_res[0];
	if (gnl_split_res[1] != NULL)
		*store = gnl_split_res[1];
	free(gnl_split_res);
	return (1);
}

int	get_buf(char buf[BUFFER_SIZE + 1], char **res, char **store, int *nl_found)
{
	char	**gnl_split_res;

	gnl_split_res = gnl_split(buf, nl_found);
	if (gnl_split_res == NULL)
	{
		clear_memory(res, store, NULL);
		return (0);
	}
	if (gnl_split_res[0] != NULL)
	{
		if (!gnl_join(res, gnl_split_res[0]))
		{
			clear_memory(res, store, gnl_split_res);
			return (0);
		}
		free(gnl_split_res[0]);
	}
	if (gnl_split_res[1] != NULL)
	{
		if (*store != NULL)
			free(*store);
		*store = gnl_split_res[1];
	}
	free(gnl_split_res);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		buf[BUFFER_SIZE + 1];
	int			nl_found;
	static char	*store = NULL;
	ssize_t		nb_read;

	res = NULL;
	nl_found = 0;
	nb_read = 1;
	if (!get_store(&res, &store, &nl_found))
		return (NULL);
	while (nb_read != 0 && !nl_found)
	{
		clear_buffer(buf);
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1 || !get_buf(buf, &res, &store, &nl_found))
		{
			clear_memory(&res, &store, NULL);
			return (NULL);
		}
	}
	return (res);
}
