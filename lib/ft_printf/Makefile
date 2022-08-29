NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include

OBJS_DIR = ./objs

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

SRCS_DIR = ./src

SRCS_NAME = ft_printf.c ft_formatlen.c \
			ft_convert_from_base.c \
			ft_output_c.c \
			ft_output_di.c \
			ft_output_p.c \
			ft_output_ps.c \
			ft_output_s.c \
			ft_output_u.c \
			ft_output_xX.c \

SRCS = $(addprefix src/, ${SRCS_NAME})

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${NAME}: mkd ${OBJS}
	@make -C ../libft
	@cp ../libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf ${OBJS_DIR}
	@make clean -C ../libft

fclean: clean
	rm -f ${NAME}
	@make fclean -C ../libft

re: fclean all

mkd:
	@mkdir -p ${OBJS_DIR}

.PHONY: all clean fclean re mkd
