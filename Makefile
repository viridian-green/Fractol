NAME = fractol
LIB = ./MLX42/build
#LIB = /Users/adelemartin/Fractol/MLX42/build
LIBA = libmlx42.a
#LIB = ./minilibx-linux
#LIBA = libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g # -fsanitize=address
RM = rm -f
SRC = *.c \
all: so_long
%.o: %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@
#linux: $(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(NAME):
$(SRC) $(LIB)/$(LIBA) $(LIBFT)/$(LIBFA)
	$(CC) $(CFLAGS) $(SRC) -L$(LIB) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -ldl -lm -lpthread -o $(NAME)
#linux: $(CC) $(CFLAGS) $(SRC) -L$(LIB) $(LIBFT)/$(LIBFA) -L/usr/MLX42 -lmlx42 -ldl -lglfw -lm -lpthread -o $(NAME)
$(LIB)/$(LIBA):
	@$(MAKE) -C $(LIB)
$(LIBFT)/$(LIBFA):
	@$(MAKE) -C $(LIBFT)
clean:
	make -C $(LIB) clean
fclean: clean
	make -C $(LIB) fclean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re