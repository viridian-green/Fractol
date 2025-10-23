CC = cc
CFLAGS = -Wall -Werror -Wextra
XTRAFLAGS = -g -Ilibft
MLX_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11 -lm

NAME = fractol
LIBFT = libft/libft.a
MLX_PATH = minilibx-linux
MLX = minilibx-linux/libmlx.a
$(MLX):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		git clone https://github.com/42paris/minilibx-linux.git $(MLX_PATH); \
	fi
	@make -C $(MLX_PATH)

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
	$(CC) $(OBJS) -L$(MLX_PATH) -lmlx $(LIBFT) -lXext -lX11 -lm -o fractol


clean:
		rm -f $(OBJS)
		rm -f $(OBJS)
	@if [ -f "$(MLX_PATH)/Makefile" ] && grep -q '^clean:' $(MLX_PATH)/Makefile; then \
		$(MAKE) clean -C $(MLX_PATH); \
	else \
		echo "Skipping MLX clean (no clean rule found)"; \
	fi
	$(MAKE) -C libft clean
		$(MAKE) -C libft clean

fclean: clean
		$(MAKE) -C libft fclean

re:		fclean all

.PHONY: all clean fclean re