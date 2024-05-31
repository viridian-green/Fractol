CC = cc
CFLAGS = -Wall -Werror -Wextra -g
XTRAFLAGS = -Ilibft
MLX_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11 -lm

NAME = fractol
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

SRC = 	main.c \
		utils.c \
		mandelbrot.c \
		color.c \
		events.c \
		init.c \
		render.c \
		julia.c \
		clean_and_exit.c \


OBJ = $(SRC:.c=.o)

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C minilibx-linux

libraries: $(LIBFT) $(MLX)

all: $(NAME)

$(NAME): $(OBJ) libraries
	$(CC) $(XTRAFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(XTRAFLAGS) -c $< -o $@



clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re