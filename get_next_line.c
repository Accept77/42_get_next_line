/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/29 19:45:34 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void read_buf(char *stay, int *fd_index, char *buf, int fd)
{
	if (stay)
	{
		*fd_index = gnl_strlen(stay);
		gnl_str_cpy(buf, stay, *fd_index);
		free(stay);
		stay = NULL;
	}
	else
		*fd_index = read(fd, buf, BUFFER_SIZE);
}

int	where_n(int fd_index, char *buf, int *flag)
{
	int	index;

	index = 0;
	while (index < fd_index)
	{
		if (buf[index] == '\n')
		{
			*flag = 0;
			index++;
			break ;
		}
		index++;
	}
	return (index);
}

char	*result_is(char *result, int *result_len, char *buf, int index)
{
	char	*tmp;

	tmp = gnl_strdup(result, *result_len);
	free(result);
	result = NULL;
	if (tmp == NULL)
		result = gnl_strdup(buf, index);
	else
		result = gnl_strjoin(tmp, buf, index, *result_len);
	free(tmp);
	tmp = NULL;
	*result_len += index;
	return (result);
}

char	*get_next_line2(char *result, char *buf, int result_len, int fd)
{
	static char	*stay;
	int			index;
	int			fd_index;
	int			flag;

	flag = 1;
	while (flag)
	{
		index = 0;
		if (stay)
		{
			fd_index = gnl_strlen(stay);
			gnl_str_cpy(buf, stay, fd_index);
			free(stay);
			stay = NULL;
		}
		else
			fd_index = read(fd, buf, BUFFER_SIZE);
		if (fd_index == 0)
			return (result);
		else if (fd_index < 0)
		{
			if (result)
				free(result);
			return (NULL);
		}
		index = where_n(fd_index, buf, &flag);
		if (index != fd_index)
			stay = gnl_strdup_stay(buf, index, fd_index);
		result = result_is(result, &result_len, buf, index);
		if (!result)
		{
			free(stay);
			stay = NULL;
		}
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char	*result;
	char	buf[BUFFER_SIZE];
	int		result_len;

	result = NULL;
	result_len = 0;
	result = get_next_line2(result, buf, result_len, fd);
	return (result);
}
