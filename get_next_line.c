/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/06 15:27:36 by jinsyang         ###   ########.fr       */
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
	int			fd_index;
	int			flag = 1;
	char	*tmp;

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
		if (index != fd_index)
			stay = gnl_strdup_stay(buf, index, fd_index);
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
		if (!result)
		{
			free(stay);
			stay = NULL;
		}
	}
	return (result);
}
