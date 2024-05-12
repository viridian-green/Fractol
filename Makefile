
NAME				=	fractol.a

# Compiler and CFlags
CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra
RM					=	rm -f

# Determine the platform
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	LIBS = -L./minilibx-macos -lmlx -framework OpenGL -framework AppKit
	MLX = ./minilibx-macos/libmlx.a
#	INC = -Iinc -Iminilibx-macos
endif

SRCS					=	main.c \

OBJ 				= 	$(SRCS:.c=.o)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


all: 					$(MLX)  $(NAME)

$(NAME): 				$(OBJ) $(MLX)
						$(CC) $(OBJ) $(MLX) $(LIBS) -o $(NAME)


$(MLX):
						@$(MAKE) -sC $(dir $(MLX)) CFLAGS="-w"



# Compile object files from source files
$(OBJ_DIR)%.o:			$(SRC_DIR)%.c
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)
						@make clean -C $(dir $(MLX))

fclean: 				clean
						@$(RM) $(NAME)
						@$(RM) $(MLX)

re: 					fclean all

# Phony targets represent actions not files
.PHONY: 				all clean fclean re
