/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:12 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/15 15:53:30 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup_stay(const char *s1, int index, int total_size)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = total_size - index;
	result = (char *) malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = s1[index];
		i++;
		index++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s1, int index)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *) malloc(sizeof(char) * index + 1);
	if (!(result))
		return (NULL);
	while (i < index)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

char	*ft_strjoin(char const *re, char const *buf, int index)
{
	int		len_s1;
	char	*result;

	if (!re && !buf)
		return (NULL);
	else if (!re)
		return (((char *)buf));
	else if (!buf)
		return (((char *)re));
	len_s1 = ft_strlen(re);
	result = (char *)malloc(sizeof(char) * (len_s1 + index + 1));
	if (!(result))
		return (NULL);
	ft_strlcpy(result, re, len_s1);
	ft_strlcpy(result + len_s1, buf, index);
	result[len_s1 + index] = '\0';
	return (result);
}
