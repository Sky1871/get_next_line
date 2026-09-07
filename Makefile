# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: sky <sky@student.42.fr>                   #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/09/07 18:17:07 by sky              #+#    #+#               #
#    Updated: 2026/09/07 18:17:32 by sky             ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MMD -MP
LDFLAGS		=
LDLIBS		=
DEBUG		?= 0
RM		= rm -f

# Optional libs: no configured optional library directory detected.
LIBS		=

JOBS		?= $(shell nproc)
MAKEFLAGS	+= -j $(JOBS) -l $(JOBS)

ifeq ($(DEBUG),1)
CFLAGS		+= -g3
CPPFLAGS	+= -DDEBUG=1
endif

SRC_DIR		= src
OBJ_DIR		= obj
SRCS		= $(SRC_DIR)/main.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
