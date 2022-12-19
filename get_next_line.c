/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/15 17:24:14 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*result;
	char		buf[BUFFER_SIZE];
	static char	*stay;
	int			index;
	int			i;
	int			flag;

	result = NULL;
	flag = 1;
	while (flag)
	{
		i = 0;
		if (stay)
		{
			index = ft_strlen(stay);
			ft_str_cpy(buf, stay, index);
			free(stay);
			stay = NULL;
		}
		else
			index = read(fd, buf, BUFFER_SIZE);
		if (index < 0)
			return (NULL);
		else if(index == 0)
			return (result);
		while (i < index)
		{
			if (buf[i] == '\n')
			{
				flag = 0;
				i++;
				break ;
			}
			i++;
		}
		if (i != index)
			stay = ft_strdup_stay(buf, i, index);
		if (result == NULL)
			result = ft_strdup(buf, i);
		else
			result = ft_strjoin(result, buf, i);
	}
	return (result);
}
