CC = cc
CFLAGS = -Wall -Werror -Wextra
XTRAFLAGS = -g -Ilibft
MLX_FLAGS = -Lmlx -L/usr/lib/X11 -lXext -lX11

NAME = fractol
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a

SRC = 	main.c \
		utils.c \
		mandelbrot.c \


OBJ = $(SRC:.c=.o)

libraries:
	$(MAKE) -C minilibx-linux
	$(MAKE) -C libft

all: libraries $(NAME)

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