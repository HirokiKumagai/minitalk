# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 09:18:03 by hkumagai          #+#    #+#              #
#    Updated: 2022/08/31 14:54:49 by hkumagai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS := -rcs
INCLUDE = -I./include
LDFLAGS = -Llib/ft_printf -Llib/libft
LIBS = -lftprintf -lft

SRCS_DIR := ./src
SRCS_DIR/ := $(if $(SRCS_DIR),$(patsubst %//,%/,$(SRCS_DIR)/),)
SERVER_SRCS := $(addprefix $(SRCS_DIR/), server.c)
CLIENT_SRCS := $(addprefix $(SRCS_DIR/), client.c)
SERVER_BONUS_SRCS := $(addprefix $(SRCS_DIR/), server_bonus.c )
CLIENT_BONUS_SRCS := $(addprefix $(SRCS_DIR/), client_bonus.c)
COMMON_BONUS_SRCS := $(addprefix $(SRCS_DIR/), receive_signal.c output_signal.c send_message.c)

OBJS_DIR := ./objs
OBJS_DIR/ := $(if $(OBJS_DIR),$(patsubst %//,%/,$(OBJS_DIR)/),)
SERVER_OBJS := $(SERVER_SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)
CLIENT_OBJS := $(CLIENT_SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)
SERVER_BONUS_OBJS := $(SERVER_BONUS_SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)
CLIENT_BONUS_OBJS := $(CLIENT_BONUS_SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)
COMMON_BONUS_OBJS := $(COMMON_BONUS_SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)

LIB_DIR := ./lib
LIB_DIR/ := $(if $(LIB_DIR),$(patsubst %//,%/,$(LIB_DIR)/),)

all: libMake $(SERVER_NAME) $(CLIENT_NAME)

clean:
	make clean -C ./lib/libft
	make clean -C ./lib/ft_printf
	rm -rf ${OBJS_DIR}

fclean: clean
	make fclean -C ./lib/libft
	make fclean -C ./lib/ft_printf
	rm -rf ${SERVER_NAME} $(CLIENT_NAME) ${SERVER_BONUS_NAME} ${CLIENT_BONUS_NAME}

re: fclean all

bonus: libMake  $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

$(SERVER_NAME):$(SERVER_OBJS)
	$(CC) $(CFLAGS) ${INCLUDE} $(SERVER_OBJS) ${LDFLAGS} ${LIBS} -o $(SERVER_NAME)

$(CLIENT_NAME):$(CLIENT_OBJS)
	$(CC) $(CFLAGS) ${INCLUDE} $(CLIENT_OBJS) ${LDFLAGS} ${LIBS} -o $(CLIENT_NAME)

$(SERVER_BONUS_NAME):$(SERVER_BONUS_OBJS) $(COMMON_BONUS_OBJS)
	$(CC) $(CFLAGS) ${INCLUDE} $(SERVER_BONUS_OBJS) $(COMMON_BONUS_OBJS) ${LDFLAGS} ${LIBS} -o $(SERVER_BONUS_NAME)

$(CLIENT_BONUS_NAME):$(CLIENT_BONUS_OBJS) $(COMMON_BONUS_OBJS)
	$(CC) $(CFLAGS) ${INCLUDE} $(CLIENT_BONUS_OBJS) $(COMMON_BONUS_OBJS) ${LDFLAGS} ${LIBS} -o $(CLIENT_BONUS_NAME)

libMake: $(OBJS_DIR/).keep libft ft_printf

libft: $(LIB_DIR/)libft/libft.a

$(LIB_DIR/)libft/libft.a:
	make -C ./lib/libft

ft_printf: $(LIB_DIR/)ft_printf/libftprintf.a

$(LIB_DIR/)ft_printf/libftprintf.a:
	make -C ./lib/ft_printf

$(SERVER_OBJS): ${OBJS_DIR/}%.o: ${SRCS_DIR/}%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(CLIENT_OBJS): ${OBJS_DIR/}%.o: ${SRCS_DIR/}%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(SERVER_BONUS_OBJS): ${OBJS_DIR/}%.o: ${SRCS_DIR/}%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(CLIENT_BONUS_OBJS): ${OBJS_DIR/}%.o: ${SRCS_DIR/}%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(COMMON_BONUS_OBJS): ${OBJS_DIR/}%.o: ${SRCS_DIR/}%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJS_DIR/).keep:
	mkdir -p $(@D)
	touch $@

.PHONY: all clean fclean re bonus libMake libft ft_printf
