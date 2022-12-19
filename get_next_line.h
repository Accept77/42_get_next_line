/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:22 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/15 17:30:57 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup_stay(char *s1, int index, int total_size);
char	*ft_strdup(char *s1, int index);
void	ft_str_cpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *re, char *buf, int index);

#endif
