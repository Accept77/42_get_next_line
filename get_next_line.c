/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:48:07 by jinsyang          #+#    #+#             */
/*   Updated: 2022/12/14 18:58:27 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*result;
	char	buf[BUFFER_SIZE];
	static char	*stay;
	int index;
	int i = 0;

	result = NULL;
	//앞에서 stay 검사해서 비여있는지 확인?
	//비여 있으면 다시 시작이고 아니면 stay부터 복사
	while () //무슨조건으로?
	{
		index = read(fd, buf, BUFFER_SIZE); //buffer size = 1? null? EOF=0?
		while (i < index)
		{
			if (buf[i] == '\n')
			{
				//이때 해당 i만큼 복사?
				break;
			}
			i++;
		}
		if (i != index - 1)
			stay = ft_strdup(buf); // 만약에 버퍼사이즈가 클경우는?
	}
	if (result == NULL)
		result = ft_strdup(buf);
	else
		ft_strjoin(result, buf);
	return (result);
}

//리턴하는 값에 아무것도 없으면 strdup
//있으면 strjoin
//buffer size 가 1일때 100000일떄 고려하기
//buffer size 가 작으면 계속 불러와서 읽기
//index 만큼만 strdup strjoin실행?
//만약 리드하다가 중간에 \n오면 저장하고 저장하는거 중간에 자르고
//다음에 실행하면 저장했다가 다시 그거부터 불러와서 시작?
