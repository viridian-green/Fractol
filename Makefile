CC = cc
NAME = fractol
FLAGS = -Wall -Werror -Wextra
LIBMLX = ./MLX42
INCLUDES = -I$(LIBMLX)/include
RM = rm -f
SRC = main.c
OBJ := $(SRC:.c=.o)
all: libmlx $(NAME)
libmlx:
	@if [ ! -d “$(LIBMLX)” ]; then\
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX);\
		cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 && make -C $(LIBMLX)/build -j4 > /dev/null 2>&1;\
		mv $(LIBMLX)/include/MLX42/MLX42_Int.h $(LIBMLX)/include/MLX42_Int.h;\
	fi
$(NAME): $(OBJ) $(LIBMLX)
	@$(CC) $(FLAGS) $(OBJ) $(INCLUDES) $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -o $(NAME)
#   $(CC) $(FLAGS) -g $(OBJ) $(LIBFT) libmlx42.a -Iinclude -lglfw -L”/opt/homebrew/Cellar/glfw/3.3.9/lib” -o $(NAME)
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
	@$(RM) -r $(LIBMLX)
re: fclean all
.PHONY: all clean fclean re