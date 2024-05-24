CC = cc
CFLAGS = -Wall -Werror -Wextra
XTRAFLAGS = -g -Ilibft
MLX_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11

NAME = fractol
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a

SRC = 	main.c \
		utils.c \
		mandelbrot.c \


OBJ = $(SRC:.c=.o)

all: libraries $(NAME)

$(NAME): $(OBJ) libraries
	$(CC) $(XTRAFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(XTRAFLAGS) -c $< -o $@

libraries:
	$(MAKE) -C minilibx
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx fclean

re: fclean all

.PHONY: all clean fclean re