/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/22 19:05:16 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// stay 유무에 따라 reulst 에 복사 아니면 buf에 복사
// 용도에 따라 함수 나누기
// 아니면 처음 다시 구성부터 갈아엎기

char *fill_buf(char *buf, char *stay, int *fd_index)
{
	int index;

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

void free_all(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line2(char *result, int fd, int fd_index, int result_len)
{ // 25line 5line del
	char		buf[BUFFER_SIZE];
	static char	*stay;
	int			index;

	index = 0;
	while (index == fd_index) // 여기 조건만 어케 만지면?
	{
		if (stay)
			stay = fill_buf(buf, stay, &fd_index);
		else
			fd_index = read(fd, buf, BUFFER_SIZE);
		if (fd_index == 0)
			return (result);
		else if (fd_index < 0)
		{
			free_all(&result);
			return (NULL);
		}
		free_all(&stay);
		index = where_n(buf, fd_index); // 여길 만저야 할듯?
		if (index != fd_index && BUFFER_SIZE != 1)
			stay = gnl_strdup(buf + index, fd_index - index);
		result = result_is(result, &result_len, buf, index);
		if (!result)
		{
			free_all(&stay);
			return (NULL);
		}
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char	*result;
	int		result_len;
	int		fd_index;

	result = NULL;
	result_len = 0;
	fd_index = 0;
	result = get_next_line2(result, fd, fd_index, result_len);
	return (result);
}
