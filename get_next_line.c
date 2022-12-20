/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/20 16:31:05 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	where_n(int i, char *buf, int *flag, int index)
{
	while (i < index)
	{
		if (buf[i] == '\n')
		{
			*flag = 0;
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*result_is(char *result, char *buf, int i)
{
	char	*tmp;

	tmp = ft_strdup(result, ft_strlen(result));
	free(result);
	result = NULL;
	if (tmp == NULL)
		result = ft_strdup(buf, i);
	else
		result = ft_strjoin(tmp, buf, i);
	free(tmp);
	tmp = NULL;
	return (result);
}

char	*get_next_line2(char *result, char *buf, int fd, int flag)
{
	static char	*stay;
	int			i;
	int			index;

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
		if (index <= 0)
			return (result);
		i = where_n(i, buf, &flag, index);
		if (i != index)
			stay = ft_strdup_stay(buf, i, index);
		result = result_is(result, buf, i);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		*result;
	char		buf[BUFFER_SIZE];
	int			flag;

	result = NULL;
	flag = 1;
	result = get_next_line2(result, buf, fd, flag);
	return (result);
}
