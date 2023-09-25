# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 14:14:05 by fgomes-c          #+#    #+#              #
#    Updated: 2023/09/25 15:00:59 by fgomes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = pipex

SRCS = pipex.c utils.c
OBJS = ${SRCS:.c=.o}
MAIN = pipex.c

INCLUDE = -I .

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

.c.o: %.o : %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o $(<:.c=.o)
			
${PROG}: ${OBJS}
		${MAKE} ${LIBFT_PATH} all
		${CC} ${OBJS} ${LIBFT} -o ${PROG}

all: ${PROG}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${make} ${LIBFT_PATH} fclean
		${RM} ${PROG}

re: fclean all

.PHONY: all clean fclean re			