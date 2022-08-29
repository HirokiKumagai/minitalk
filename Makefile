# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 09:18:03 by hkumagai          #+#    #+#              #
#    Updated: 2022/08/29 21:45:37 by hkumagai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./include
LDFLAGS = -Llib/ft_printf -Llib/libft
LIBS = -lftprintf -lft

SERVER_NAME = server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

SRCS_DIR = ./src
SERVER_SRC = server.c
CLIENT_SRC = client.c
SERVER_BONUS_SRC = server_bonus.c send_message.c receive_signal.c
CLIENT_BONUS_SRC = client_bonus.c send_message.c

OBJS_DIR = ./objs
SERVER_OBJ = $(addprefix $(OBJS_DIR)/, $(notdir $(SERVER_SRC:.c=.o)))
CLIENT_OBJ = $(addprefix $(OBJS_DIR)/, $(notdir $(CLIENT_SRC:.c=.o)))
SERVER_BONUS_OBJ = $(addprefix $(OBJS_DIR)/, $(notdir $(SERVER_BONUS_SRC:.c=.o)))
CLIENT_BONUS_OBJ = $(addprefix $(OBJS_DIR)/, $(notdir $(CLIENT_BONUS_SRC:.c=.o)))

TEST_CASE1 = minitalk
TEST_CASE2 = 42Tokyo

all: ${SERVER_NAME} ${CLIENT_NAME}

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
	@rm -rf ${SERVER_NAME} ${CLIENT_NAME} ${SERVER_BONUS_NAME} ${CLIENT_BONUS_NAME} \
	b_${SERVER_BONUS_NAME} b_${CLIENT_BONUS_NAME}
	@make clean -C ./lib/ft_printf

fclean: clean
	@rm -r ./objs
	@make fclean -C ./lib/ft_printf

re: fclean all

re_bonus: fclean bonus

test: all pre_test
	@echo "TEST_CASE1"
	@pgrep test_${SERVER_NAME} | xargs -i ./test_${CLIENT_NAME} {} ${TEST_CASE1}
	@echo;
	@echo "TEST_CASE2"
	@pgrep test_${SERVER_NAME} | xargs -i ./test_${CLIENT_NAME} {} ${TEST_CASE2}
	@echo;
	@pgrep test_${SERVER_NAME} | xargs kill -9
	@rm test_${SERVER_NAME} test_${CLIENT_NAME}

pre_test:
	$(CC) $(CFLAGS) ${SERVER_NAME} -o test_${SERVER_NAME}
	$(CC) $(CFLAGS) ${CLIENT_NAME} -o test_${CLIENT_NAME}
	./test_${SERVER_NAME} &
	@sleep 1

kill_ps:
	@pgrep ${SERVER_NAME} | xargs kill -9

mkd:
	@mkdir -p ${OBJS_DIR}

bonus: ${SERVER_BONUS_NAME} ${CLIENT_BONUS_NAME}

${SERVER_BONUS_NAME}: mkd libMake ${SERVER_BONUS_OBJ}
	@cp ./lib/ft_printf/libftprintf.a ${SERVER_BONUS_NAME}
	@ar -rcs $(SERVER_BONUS_NAME) $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) ${SERVER_BONUS_NAME} -o b_${SERVER_BONUS_NAME}

${CLIENT_BONUS_NAME}:mkd libMake ${CLIENT_BONUS_OBJ}
	@cp ./lib/ft_printf/libftprintf.a ${CLIENT_BONUS_NAME}
	@ar -rcs $(CLIENT_BONUS_NAME) $(CLIENT_BONUS_OBJ)
	$(CC) $(CFLAGS) ${CLIENT_BONUS_NAME} -o b_${CLIENT_BONUS_NAME}

bonus_pre_test:
	./b_${SERVER_BONUS_NAME} &
	@sleep 2

bonus_test: bonus bonus_pre_test
	@echo "TEST_CASE1"
	@pgrep b_${SERVER_BONUS_NAME} | xargs -i ./b_${CLIENT_BONUS_NAME} {} ${TEST_CASE1}
	@echo;
	@echo "TEST_CASE2"
	@pgrep b_${SERVER_BONUS_NAME} | xargs -i ./b_${CLIENT_BONUS_NAME} {} ${TEST_CASE2}
	@echo;
	@pgrep b_${SERVER_BONUS_NAME} | xargs kill
	@rm b_${SERVER_BONUS_NAME} b_${CLIENT_BONUS_NAME}

.PHONY: all clean fclean re mkd libMake test pre_test kill_ps \
		bonus bonus_pre_test bonus_test re_bonus
