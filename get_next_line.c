/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/24 17:38:00 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*result = NULL;
	char		buf[BUFFER_SIZE];
	static char	*stay;
	int			index;
	int			fd_index;
	char		*tmp = NULL;
	int		flag = 1;

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
			{
				free(result);
				result = NULL;
			}
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
		{
			stay = gnl_strdup_stay(buf, index, fd_index);
			if(stay == NULL)
				return (NULL);
		}

		tmp = gnl_strdup(result, gnl_strlen(result));
		free(result);
		result = NULL;

		if (tmp == NULL)
			result = gnl_strdup(buf, index);
		else
			result = gnl_strjoin(tmp, buf, index);
		if (result == NULL)
			return(NULL);
		free(tmp);
		tmp = NULL;
	}
	return (result);
}
