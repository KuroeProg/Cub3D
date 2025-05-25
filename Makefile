# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 16:04:41 by tbahin            #+#    #+#              #
#    Updated: 2025/05/25 19:36:46 by tbahin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

INCLUDE = ./includes/

CC = cc
CFLAG = -Wall -Wextra -Werror -g

SRCS =./srcs/parsing/check_map.c ./srcs/parsing/init_data.c ./srcs/display_2d.c \
./srcs/main.c ./srcs/free_mlx.c ./srcs/key.c

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
