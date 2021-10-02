# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 13:00:20 by ltouret           #+#    #+#              #
#    Updated: 2021/10/03 01:04:39 by ltouret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = checker

SRCS = srcs/main.c srcs/utils.c srcs/exit.c srcs/lst_func.c \
	srcs/parsing.c srcs/replace_num.c srcs/create_arr.c \
	srcs/operations1.c srcs/operations2.c \
	srcs/sort.c srcs/sort_utils.c \
	srcs/ft_split.c

BONUS = bonus/main.c bonus/utils.c bonus/exit.c bonus/lst_func.c \
	bonus/parsing.c bonus/replace_num.c bonus/create_arr.c \
	bonus/operations1.c bonus/operations2.c \
	bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c \
	bonus/ft_split.c bonus/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o} 

CC		= clang
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

FSAN = -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${OBJS} -o ${NAME} 

bonus: ${OBJS} ${OBJSBONUS}
		${CC} ${OBJS} -o ${NAME} 
		${CC} ${OBJSBONUS} -o ${NAME2} 

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME} ${NAME2}

re:		fclean all

test:	bonus
		@#./push_swap 7 6 3 4 -19 2 123
		@#./push_swap 3 2 5 1
		@#./push_swap 3 2 1 5 7
		@#./push_swap 7 6
		@#./push_swap "    87  -487  781      -100  101  0  1"
		@#./push_swap +171 -13 148 #this breaks!

.PHONY: bonus all clean fclean re test
