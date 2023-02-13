/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/13 19:08:38 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line2(char *result, int fd, int fd_index, int result_len)
{
	char	buf[BUFFER_SIZE];
	static char	*stay;
	int			index;
	int			flag;

	flag = 1;
	while (flag)
	{
		index = 0;
		if (stay)
		{
			while (stay[fd_index])
			{
				buf[fd_index] = stay[fd_index];
				fd_index++;
			}
			free(stay);
			stay = NULL;
		}
		else
			fd_index = read(fd, buf, BUFFER_SIZE);
		if (fd_index == 0)
			return (result);
		else if (fd_index < 0)
		{
			free(result);
			return (NULL);
		}
		index = where_n(buf, fd_index, &flag);
		if (index != fd_index)
			stay = gnl_strdup(buf + index, fd_index - index);
		result = result_is(result, result_len, buf, index);
		result_len += index;
		if (!result)
		{
			free(stay);
			stay = NULL;
			return (NULL);
		}
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char	*result = NULL;
	int		result_len;
	int			fd_index;

	result_len = 0;
	fd_index = 0;
	result = get_next_line2(result, fd, fd_index, result_len);
	return (result);
}
