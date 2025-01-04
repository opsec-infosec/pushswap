# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 22:28:32 by dfurneau          #+#    #+#              #
#    Updated: 2021/12/10 15:04:35 by dfurneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS		=	checker
LIBFT		=	libft.a

SSRCS		=	push_swap.c error.c parser.c memory_mng.c memory_mng_ops.c\
				p_swap.c p_push.c p_rotate.c p_r_rotate.c \
				helper_find_func.c helper_sort_func.c helper_sort_func100.c \
				helper_locate_func.c sorting.c execute.c

BSRCS		=	checker.c parser_checker.c error.c parser.c memory_mng.c \
				p_swap.c p_push.c p_rotate.c p_r_rotate.c helper_sort_func.c \

SOBJS		=	${SSRCS:.c=.o}
BOBJS		=	${BSRCS:.c=.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g3
CHKR		=	-D CHECKER=1
LIBC		=	ar rcs
RM			=	rm -f


${NAME}:
			${MAKE} all -C ./libft
			cp ./libft/${LIBFT} .
			${CC} ${CFLAGS} ${DEBUG} ${SSRCS} ${LIBFT} -o ${NAME} -I includes

all:		${NAME}

bonus:
			${MAKE} all -C ./libft
			cp ./libft/${LIBFT} .
			${CC} ${CFLAGS} ${DEBUG} ${CHKR} ${BSRCS} ${LIBFT} -o ${BONUS} -I includes

clean:
			${RM} ${SOBJS} ${NAME}
			${RM} ${BOBJS} ${BONUS}

fclean:		clean
			${RM} ${LIBFT}
			${MAKE} fclean -C ./libft

re:			fclean all bonus

.PHONY : all bonus clean re fclean
