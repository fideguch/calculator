# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytanooka <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 12:45:14 by ytanooka          #+#    #+#              #
#    Updated: 2020/04/09 19:17:08 by ytanooka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c ft_putchar.c ft_putnbr.c eval_expr.c calc.c is.c atoip.c
OBJS    = ${SRCS:.c=.o}
NAME    = eval_expr
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}
all: ${NAME}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re .c.o
