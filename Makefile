CC = cc
CFLAGS = -Wall -Werror -Wextra
XTRAFLAGS = -g -Ilibft
MLX_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11 -lm

NAME = fractol
LIBFT = libft/libft.a
MLX_PATH = minilibx-linux
MLX:
	@if [ ! -d "minilibx-linux/libmlx.a" ]; then \
		git clone https://github.com/42paris/minilibx-linux.git minilibx-linux/libmlx.a; \
	fi
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	@make --quiet -C $(MLX)/build -j4

SRC = 	main.c \
		utils.c \
		mandelbrot.c \
		color.c \
		events.c \
		init.c \
		render.c \
		julia.c \
		clean_and_exit.c \
		utils_color.c

OBJS = $(SRC:.c=.o)

all:	$(NAME) $(MLX)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(MAKE) -C $(MLX_PATH)
	$(CC) $(OBJS) -L$(MLX_PATH) $(LIBFT) -lmlx_Linux -lX11 -lXext -lm -o $(NAME)

clean:
		rm -f $(OBJS)
		$(MAKE) clean -C $(MLX_PATH)
		$(MAKE) -C libft clean

fclean: clean
		rm -f $(NAME) $(MLX)
		rm -f $(NAME) $(LIBFT)
		$(MAKE) -C libft fclean

re:		fclean all

.PHONY: all clean fclean re