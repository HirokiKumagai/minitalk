# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 09:18:03 by hkumagai          #+#    #+#              #
#    Updated: 2022/08/25 17:09:44 by hkumagai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./include
LDFLAGS = -Llib/ft_printf -Llib/libft
LIBS = -lftprintf -lft

SERVER_NAME = server
CLIENT_NAME = client

SRCS_DIR = ./src
SERVER_SRC = server.c
CLIENT_SRC = client.c

OBJS_DIR = ./objs
SERVER_OBJ = $(addprefix $(OBJS_DIR)/, $(notdir $(SERVER_SRC:.c=.o)))
CLIENT_OBJ = $(addprefix $(OBJS_DIR)/, $(notdir $(CLIENT_SRC:.c=.o)))

all:${SERVER_NAME} ${CLIENT_NAME}

libMake:
	@make -C ./lib/ft_printf

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE) -c $< -o $@

${SERVER_NAME}:mkd libMake ${SERVER_OBJ}
	@cp ./lib/ft_printf/libftprintf.a ${SERVER_NAME}
	@ar -rcs $(SERVER_NAME) $(SERVER_OBJ)

${CLIENT_NAME}:mkd libMake ${CLIENT_OBJ}
	@cp ./lib/ft_printf/libftprintf.a ${CLIENT_NAME}
	@ar -rcs $(CLIENT_NAME) $(CLIENT_OBJ)

clean:
	@rm -rf ${SERVER_NAME} ${CLIENT_NAME}
	@make clean -C ./lib/ft_printf

fclean: clean
	@rm -r ./objs
	@make fclean -C ./lib/ft_printf

re: fclean all

mkd:
	@mkdir -p ${OBJS_DIR}

.PHONY: all clean fclean re mkd libMake
