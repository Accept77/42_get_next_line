/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/06 17:45:03 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*result = NULL;
	char	buf[BUFFER_SIZE];
	int		result_len = 0;
	static char	*stay;
	int			index;
	int			fd_index = 0;
	int			flag = 1;
	char	*tmp;

	while (flag)
	{
		index = 0;
		if (stay) // 1번
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
		while (index < fd_index)
		{
			if (buf[index] == '\n')
			{
				flag = 0;
				index++;
				break ;
			}
			index++;
		}
		if (index != fd_index) // 1번 하고 while 종료
			stay = gnl_strdup(buf + index, fd_index - index);
		tmp = gnl_strdup(result, result_len);
		free(result);
		result = NULL;
		if (tmp == NULL)
			result = gnl_strdup(buf, index);
		else
			result = gnl_strjoin(tmp, buf, index, result_len);
		free(tmp);
		tmp = NULL;
		result_len += index;
		if (!result) // 여기도?
		{
			free(stay);
			stay = NULL;
			return (NULL);
		}
	}
	return (result);
}
