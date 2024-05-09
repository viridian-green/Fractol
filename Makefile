NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(NAME)

$(MLX):
						@if [ "$(UNAME_S)" = "Linux" ]; then \
							make -sC ./minilibx-linux; \
						else \
							make -sC ./minilibx-macos; \
						fi

clean:
	RM $(NAME)
	RM $(OBJS)

fclean : clean
	RM $(NAME)

re: fclean all

.PHONY: all clean fclean re