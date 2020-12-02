# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <dchampda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 12:24:14 by user42            #+#    #+#              #
#    Updated: 2020/11/04 12:24:15 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libasm.a
NA =		nasm
NAFLAGS =	-f elf64

CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s
OBJS =	${SRCS:.s=.o}

.s.o:
	${NA} ${NAFLAGS} -s $< -o ${<:.s=.o}

all: ${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

ccmain:
	${CC} ${CLFAGS} main.c ${NAME}

clean:
	rm -f ${OBJS}
	rm -f example.txt

fclean: clean
	rm -f ${NAME}
	rm -f ./a.out

re: fclean
	$(MAKE)