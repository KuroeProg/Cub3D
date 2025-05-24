# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 16:04:41 by tbahin            #+#    #+#              #
#    Updated: 2025/05/24 16:30:52 by tbahin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

INCLUDE = ./includes/

CC = cc
CFLAG = -Wall -Wextra -Werror -g

SRCS =./parsing/check_map.c ./parsing/init_data.c main.c

OBJS = ${SRCS:.c=.o}

all : ${NAME} 

${NAME} : $(OBJS)
	make bonus -C ./libft
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) -L./libft -lft

bonus: $(OBJSB)
	make bonus -C ./libft
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) -L./libft -lft

%.o: %.c
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< -o $@

clean :
	rm -f ${OBJS}
	make clean -C ./libft

fclean : clean
	rm -f ${NAME}
	make fclean -C ./libft

re : fclean all

.phony : all clean fclean re bonus
