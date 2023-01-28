/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:49:22 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/28 15:54:06 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	gnl_strlen(char *str);
char	*gnl_strdup_stay(char *buf, int index, int fd_index);
char	*gnl_strdup(char *s1, int index);
void	gnl_str_cpy(char *dst, char *src, size_t dstsize);
char	*gnl_strjoin(char *tmp, char *buf, int index, int result_len);

#endif
