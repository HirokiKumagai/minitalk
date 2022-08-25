# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 09:18:03 by hkumagai          #+#    #+#              #
#    Updated: 2022/08/25 03:53:24 by hkumagai         ###   ########.fr        #
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

# TEST_DIR = ./test

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${NAME}: mkd ${OBJS}
	@make -C ./libft
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf ${OBJS_DIR}
	# @rm -f test.out
	@make clean -C ./libft

fclean: clean
	rm -f ${NAME}
	@make fclean -C ./libft

re: fclean all

# test: all
# 	@${CC} ${TEST_DIR}/main.c ${NAME} -o test.out
# 	@./test.out

mkd:
	@mkdir -p ${OBJS_DIR}

.PHONY: all clean fclean re mkd
