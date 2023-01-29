/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:12 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/29 16:38:47 by jinsyang         ###   ########.fr       */
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
	if (index == 0)
	{
		result[0] = '\0';
		return (result);
	}
	while (i < index && s1[i])
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
	while (i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*gnl_strjoin(char *tmp, char *buf, int index, int result_len)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (result_len + index + 1));
	if (!result)
		return (NULL);
	gnl_str_cpy(result, tmp, result_len);
	gnl_str_cpy(result + result_len, buf, index);
	return (result);
}
