NAME = so_long

CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs/
UTILS_DIR = utils/
PRINTF_DIR = utils/ft_printf
MINILIBX_DIR = .minilibx-linux

SRCS = $(SRCS_DIR)/main.c \
	$(SRCS_DIR)/key_handler.c \
	$(SRCS_DIR)/move.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/parsing.c \
	$(SRCS_DIR)/parsing_bis.c \
	$(SRCS_DIR)/check_mapbis.c \
	$(SRCS_DIR)/check_map.c \
	$(UTILS_DIR)utils2.c \
	$(UTILS_DIR)/gnl/get_next_line.c \
	$(UTILS_DIR)/gnl//get_next_line_utils.c \
	$(UTILS_DIR)utils.c

OBJS = $(SRCS:.c=.o)

MLX_LIB = -L $(MINILIBX_DIR) -lmlx -lX11 -lXext -lbsd
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I . -I $(MINILIBX_DIR) -I $(UTILS_DIR) -I $(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_LIB) $(MINILIBX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(PRINTF_LIB) -o $(NAME)

$(MINILIBX_DIR)/libmlx.a:
	$(MAKE) -C $(MINILIBX_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean


re: fclean all

.PHONY: all clean fclean re
