# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 09:18:03 by hkumagai          #+#    #+#              #
#    Updated: 2022/08/25 17:13:17 by hkumagai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include

OBJS_DIR = ./objs

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

SRCS_DIR = ./src

SRCS_NAME = ./server.c \

SRCS = $(addprefix src/, ${SRCS_NAME})

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${NAME}: mkd ${OBJS}
	@make -C ./lib/ft_printf
	@cp ./lib/ft_printf/libftprintf.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)

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
