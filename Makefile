# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 16:55:22 by jinsyang          #+#    #+#              #
#    Updated: 2022/12/13 16:58:46 by jinsyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_M = get_next_line.c get_next_line.h get_next_line_utils.c

SRC_B = 

OBJ_M = $(SRC_M:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

ifdef WITH_BONUS
	OBJ = $(OBJ_M) $(OBJ_B)
else
	OBJ = $(OBJ_M)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rsc $@ $^

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

clean:
	rm -rf $(OBJ_M) $(OBJ_B)

fclean: clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re all bonus
