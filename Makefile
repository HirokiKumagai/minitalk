# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 09:18:03 by hkumagai          #+#    #+#              #
#    Updated: 2022/08/25 08:46:53 by hkumagai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include

OBJS_DIR = ./objs

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

SRCS_DIR = ./src

SRCS_NAME = ./server.c \

SRCS = $(addprefix src/, ${SRCS_NAME})

all: libMake ${NAME}

libMake:
	@make -C ./lib/ft_printf
	@make -C ./lib/libft

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${NAME}: mkd ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} ./lib/ft_printf/libftprintf.a -o ${NAME}

clean:
	rm -rf ${OBJS_DIR}
	@make clean -C ./lib/ft_printf

fclean: clean
	rm -f ${NAME}
	@make fclean -C ./lib/ft_printf

re: fclean all

mkd:
	@mkdir -p ${OBJS_DIR}

.PHONY: all clean fclean re mkd
