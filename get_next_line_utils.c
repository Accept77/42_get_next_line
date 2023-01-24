/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:12 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/24 16:07:54 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (count);
	while (str[count])
		count++;
	return (count);
}

char	*gnl_strdup_stay(char *buf, int index, int fd_index)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = fd_index - index;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = buf[index];
		i++;
		index++;
	}
	result[i] = '\0';
	return (result);
}

char	*gnl_strdup(char *s1, int index)
{
	char	*result;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	result = (char *) malloc(sizeof(char) * index + 1);
	if (!result)
		return (NULL);
	while (i < index)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	gnl_str_cpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*gnl_strjoin(char *tmp, char *buf, int index)
{
	int		len_tmp;
	char	*result;

	len_tmp = gnl_strlen(tmp);
	result = (char *)malloc(sizeof(char) * (len_tmp + index + 1));
	if (!result)
		return (NULL);
	gnl_str_cpy(result, tmp, len_tmp);
	gnl_str_cpy(result + len_tmp, buf, index);
	return (result);
}
