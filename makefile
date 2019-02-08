# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/06 19:11:00 by gmonacho     #+#   ##    ##    #+#        #
#    Updated: 2019/02/08 15:43:28 by gmonacho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

SRC = ./src/main.c \
	  ./src/parser.c \
	  ./src/line_put.c \
	  ./src/create_point.c \
	  ./src/radian.c \
	  ./src/axes_put.c \
	  ./src/is_in_screen.c \
	  ./src/close_window.c \
	  ./src/rotate_x.c \
	  ./src/rotate_y.c \
	  ./src/create_vpoint.c \
	  ./src/map_put.c \
	  ./src/rotate_z.c \
	  ./src/mouse_rotation.c \
	  ./src/window_loop.c \
	  ./src/open_window.c \
	  ./src/project_vectors.c \
	  ./src/get_incre_color.c \
	  ./src/get_decre_color.c \
	  ./src/free_fdf.c \
	  ./src/corner1.c \
	  ./src/corner2.c \
	  ./src/corner3.c \
	  ./src/corner4.c \
	  ./src/refresh_window.c \
	  ./src/rotate.c \
	  ./src/key_press.c \
	  ./src/key_release.c

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

MLX = ./minilibx_macos/libmlx.a

FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FRAMEWORK) $(MLX) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft/

$(MLX):
	make -C minilibx_macos

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C minilibx_macos

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C minilibx_macos

re: fclean all

.PHONY: all clean fclean re 
