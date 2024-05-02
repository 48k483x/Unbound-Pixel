# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 11:47:08 by achahrou          #+#    #+#              #
#    Updated: 2024/01/07 15:55:27 by achahrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit 
SRC = so_long.c ./utils/mapsReading.c ./utils/get_next_line_utils.c \
		./utils/get_next_line.c  ./utils/player.c  ./utils/render_images.c \
		./utils/animate_player.c ./utils/move_player.c ./utils/twichiat.c \
		./utils/enemy_settings.c ./utils/ft_itoa.c
OBJ = *.o
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(MLXFLAGS) -o $(NAME)
$(OBJ): $(SRC)
	cc $(FLAGS) -c $(SRC)
clean: $(OBJ)
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
