# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: sky <sky@student.42.fr>                   #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/09/07 18:17:07 by sky              #+#    #+#               #
#    Updated: 2026/09/07 18:28:19 by sky             ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
CC = cc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD -MP
RM = rm -f

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} $@ ${OBJS}

clean:
	${RM} ${OBJS} ${OBJS:.o=.d}

fclean: clean
	${RM} ${NAME}

re: fclean all

-include ${OBJS:.o=.d}

.PHONY: all clean fclean re
