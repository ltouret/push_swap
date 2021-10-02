# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 13:00:20 by ltouret           #+#    #+#              #
#    Updated: 2021/10/03 01:24:08 by ltouret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c srcs/utils.c srcs/exit.c srcs/lst_func.c \
	srcs/parsing.c srcs/replace_num.c srcs/create_arr.c \
	srcs/operations1.c srcs/operations2.c \
	srcs/sort.c srcs/sort_utils.c \
	srcs/ft_split.c \

OBJS = ${SRCS:.c=.o}

CC		= clang
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

FSAN = -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

test:	all

.PHONY: all clean fclean re test
