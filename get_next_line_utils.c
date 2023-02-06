/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:12 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/06 17:49:24 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



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

char	*gnl_strjoin(char *tmp, char *buf, int index, int result_len)
{
	char	*result;
	int		i;
	int		j;

	result = (char *)malloc(sizeof(char) * (result_len + index + 1));
	i = 0;
	j = 0;
	if (!result)
		return (NULL);
	while (i < result_len)
	{
		result[j] = tmp[i];
		i++;
		j++;
	}
	i = 0;
	while (i < index)
	{
		result[j] = buf[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
