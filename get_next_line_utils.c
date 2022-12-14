/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:12 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/14 18:06:30 by jinsyang         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	result = (char *) malloc(sizeof(char) * s1_len + 1);
	if (!(result))
		return (NULL);
	while (s1[i])
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	len_s1;
	int	len_s2;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (((char *)s2));
	else if (!s2)
		return (((char *)s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!(result))
		return (NULL);
	ft_strlcpy(result, s1, len_s1);
	ft_strlcpy(result + len_s1, s2, len_s2);
	result[len_s1 + len_s2] = '\0';
	return (result);
}
