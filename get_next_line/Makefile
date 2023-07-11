# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfiliagg <dfiliagg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 10:46:16 by dfiliagg          #+#    #+#              #
#    Updated: 2023/06/20 12:37:15 by dfiliagg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line
FLAGS	=  -Wall -Wextra -Werror
CC		= gcc ${FLAGS}
RM		= rm -f
SRC		= get_next_line.c get_next_line_utils.c
OBJ		= ${SRC:.c=.o}

all: ${NAME}

.o:.c
	${CC} ${OBJ} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}
	make clean

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
