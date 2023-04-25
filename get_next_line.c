/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/04/25 19:09:04 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_null(char **str, int *flag)
{
	*flag = 0;
	free(*str);
	*str = NULL;
}

char	*fill_buf(char *buf, char *stay, int *fd_index)
{
	int	index;

	index = 0;
	while (stay[index] != '\0')
	{
		buf[index] = stay[index];
		index++;
	}
	free(stay);
	*fd_index = index;
	return (NULL);
}

char	*get_next_line2(char *result, int fd, int fd_index, int result_len)
{
	char		buf[BUFFER_SIZE];
	static char	*stay;
	int			index;
	int			flag;

	flag = 1;
	while (flag)
	{
		if (stay)
			stay = fill_buf(buf, stay, &fd_index);
		else
			fd_index = read(fd, buf, BUFFER_SIZE);
		if (fd_index < 0)
			free_and_null(&result, &flag);
		if (fd_index <= 0)
			return (result);
		index = where_n(buf, fd_index, &flag);
		if (index != fd_index && BUFFER_SIZE != 1)
			stay = gnl_strdup(buf + index, fd_index - index);
		result = result_is(result, &result_len, buf, index);
		if (!result)
			free_and_null(&stay, &flag);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char	*result;
	int		result_len;
	int		fd_index;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	result_len = 0;
	fd_index = 0;
	result = get_next_line2(result, fd, fd_index, result_len);
	return (result);
}
