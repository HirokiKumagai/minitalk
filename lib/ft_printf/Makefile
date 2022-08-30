NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

ARFLAGS := -rcs

INCLUDE = -I./include

RM = rm -rf

SRCS_DIR = ./src

SRCS_DIR/ := $(if $(SRCS_DIR),$(patsubst %//,%/,$(SRCS_DIR)/),)

SRCS := $(addprefix $(SRCS_DIR/),ft_printf.c ft_formatlen.c \
			ft_convert_from_base.c ft_output_c.c ft_output_di.c \
			ft_output_p.c ft_output_ps.c ft_output_s.c \
			ft_output_u.c ft_output_xX.c)

OBJS_DIR = ./objs

OBJS_DIR/ := $(if $(OBJS_DIR),$(patsubst %//,%/,$(OBJS_DIR)/),)

OBJS := $(SRCS:$(SRCS_DIR/)%.c=$(OBJS_DIR/)%.o)

OUTPUT_DIR := .

OUTPUT_DIR/ := $(if $(OUTPUT_DIR),$(patsubst %//,%/,$(OUTPUT_DIR)/),)

all: ${NAME}

$(NAME): $(OBJS) $(OUTPUT_DIR/).keep
	ar $(ARFLAGS) $@ $(OBJS) $(OUTPUT_DIR/).keep

clean:
	${RM} ${OBJS_DIR} $(OUTPUT_DIR/).keep

fclean: clean
	${RM} ${NAME}

re: fclean all

$(OBJS_DIR/)%.o: $(SRCS_DIR/)%.c $(OBJS_DIR/).keep
	$(COMPILE.c) $< -o $@

$(OUTPUT_DIR/).keep $(OBJS_DIR/).keep:
	mkdir -p $(@D)
	touch $@

.PHONY: all clean fclean re




