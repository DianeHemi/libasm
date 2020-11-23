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

SRCS =	ft_strlen.s
OBJS =	${SRCS:.s=.o}

.s.o:
	${NA} ${NAFLAGS} -s $< -o ${<:.s=.o}

all: ${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean
	$(MAKE)