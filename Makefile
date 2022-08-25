# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 09:18:03 by hkumagai          #+#    #+#              #
#    Updated: 2022/08/25 14:46:47 by hkumagai         ###   ########.fr        #
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

all: libMake ${SERVER_NAME} ${CLIENT_NAME}

libMake:
	@make -C ./lib/ft_printf
	@make -C ./lib/libft

${SERVER_NAME}:
	$(CC) $(CFLAGS) $(INCLUDE) $(addprefix ${SRCS_DIR}/, ${SERVER_SRC}) ${LDFLAGS} ${LIBS} -o $(SERVER_NAME)

${CLIENT_NAME}:
	$(CC) $(CFLAGS) $(INCLUDE) $(addprefix ${SRCS_DIR}/, ${CLIENT_SRC}) ${LDFLAGS} ${LIBS} -o $(CLIENT_NAME)

clean:
	rm -rf ${SERVER_NAME} ${CLIENT_NAME}
	@make clean -C ./lib/ft_printf
	@make clean -C ./lib/libft

fclean: clean
	@make fclean -C ./lib/ft_printf
	@make fclean -C ./lib/libft

re: fclean all

.PHONY: all clean fclean re mkd
