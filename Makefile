# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 16:04:41 by tbahin            #+#    #+#              #
#    Updated: 2025/06/30 22:45:14 by tbahin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDE = ./includes/

CC = clang
CFLAG = -Wall -Wextra -Werror -g -O3 -gdwarf-4

SRCS =./srcs/parsing/check_map.c ./srcs/parsing/init_data.c ./srcs/display.c \
./srcs/main.c ./srcs/free_mlx.c ./srcs/key.c ./srcs/draw.c ./srcs/move.c\
./srcs/dda.c ./srcs/drawline.c ./srcs/door.c ./srcs/parsing/texture.c \
./srcs/parsing/check_map2.c ./srcs/parsing/check_map3.c \
./srcs/parsing/check_map5.c ./srcs/parsing/check_map4.c

OBJS = ${SRCS:.c=.o}

all : ${NAME} 

${NAME} : $(OBJS)
	make bonus -C ./libft
	make -C ./.minilibx-linux
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) -L./libft -L./.minilibx-linux -lm -lft -lmlx -lXext -lX11

bonus: $(OBJSB)
	make bonus -C ./libft
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) -L./libft -lft

%.o: %.c
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< -o $@

clean :
	rm -f ${OBJS}
	make clean -C ./libft
	make clean -C ./.minilibx-linux
fclean : clean
	rm -f ${NAME}
	make fclean -C ./libft
	make clean -C ./.minilibx-linux
re : fclean all

.phony : all clean fclean re bonus
