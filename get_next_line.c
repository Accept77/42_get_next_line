/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/17 17:40:11 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// stay 유무에 따라 reulst 에 복사 아니면 buf에 복사
// 용도에 따라 함수 나누기
// 아니면 처음 다시 구성부터 갈아엎기

void free_stay(char *stay)
{
	free(stay);
}

char	*get_next_line2(char *result, int fd, int fd_index, int result_len)
{ // 25line 하나 함수 더 만들어서 나누기 ㄱ..그만
	char		buf[BUFFER_SIZE];
	static char	*stay;
	int			index;
	int			flag; // 필요?

	flag = 1;
	while (flag)
	{
		if (stay) //buf가 변경안된다면 차라리 다 비우고 넣
			while (stay[++fd_index])
				buf[fd_index] = stay[fd_index];
		else
			fd_index = read(fd, buf, BUFFER_SIZE);
		free_stay(stay); // !!! free 자체는 다른 함수 X
		stay = NULL; // !!! 이게 문제였던
		if (fd_index == 0)
			return (result);
		else if (fd_index < 0)
		{
			free(result); // !!!
			return (NULL);
		}
		index = where_n(buf, fd_index, &flag);
		if (index != fd_index)
			stay = gnl_strdup(buf + index, fd_index - index);
		result = result_is(result, &result_len, buf, index);
		if (!result) // !!!
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
	char	*result;
	int		result_len;
	int		fd_index;

	result = NULL;
	result_len = 0;
	fd_index = -1;
	result = get_next_line2(result, fd, fd_index, result_len);
	return (result);
}
