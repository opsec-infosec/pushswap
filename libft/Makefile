# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 20:54:53 by dfurneau          #+#    #+#              #
#    Updated: 2021/12/01 17:12:49 by dfurneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
PRINTF	=	libftprintf.a
GNL		=	libgnl.a

P_D 	=	./ft_printf
G_D 	= 	./get_next_line

SRCS	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_calloc.c ft_strdup.c ft_strjoin.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_split.c \
			ft_putnbr_fd.c ft_substr.c ft_strtrim.c ft_itoa.c ft_striteri.c \
			ft_strmapi.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c ft_putnumber.c ft_atol.c ft_swap.c ft_abs.c

OBJS	=	${SRCS:.c=.o}

PF_H	=	./ft_printf/includes/ft_printf.h
GNL_H 	=	./get_next_line/get_next_line.h
LFT_H	=	./libft.h
INC		=	./includes/
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG	=	-g
LIBC	=	ar -rcs
RM		=	rm -f

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -c ${SRCS}
			${LIBC} T${NAME} ${OBJS}
			cp T${NAME} ${P_D}/${PRINTF}
			${MAKE} wlibft -C ./ft_printf
			cp ${P_D}/${PRINTF} ${G_D}/${GNL}
			${MAKE} libft -C ./get_next_line
			cp ${G_D}/${GNL} ${NAME}
			cp ${PF_H} ${INC} && cp ${GNL_H} ${INC} && cp ${LFT_H} ${INC}
			${RM} T${NAME}

all:		${NAME}


printf:
			${MAKE} all -C ./ft_printf
			cp ${P_D}/${PRINTF} ./
			cp ${PF_H} ${INC}

gnl:
			${MAKE} all -C ./get_next_line
			cp ${G_D}/${GNL} ./
			cp ${GNL_H} ${INC}

libft:		${OBJS}
			${CC} ${CFLAGS} -c ${SRCS}
			${LIBC} ${NAME} ${OBJS}
			cp ${LFT_H} ${INC}

clean:
			${RM} ${OBJS}
			${MAKE} clean -C ./ft_printf
			${MAKE} clean -C ./get_next_line

fclean:		clean
			${RM} ${NAME} ${PRINTF} ${GNL}
			${MAKE} fclean -C ./ft_printf
			${MAKE} fclean -C ./get_next_line

re:			fclean all printf gnl libft

.PHONY : all printf gnl libft clean bonus re fclean
