CFILES =  main.c \
		parsing.c \
		bresenham.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -Lmlx_linux -lXext -lX11

OFILES = $(CFILES:.c=.o)

NAME = fdf

all: $(NAME)

$(NAME): $(OFILES) ./libft/*.o
	@make -C ./libft
	@make -C ./minilibx-linux
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(CFILES) ./libft/libft.a ./minilibx-linux/libmlx.a

%.o: %.c fdf.h ./libft/*.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	@make clean -C ./libft
	@make clean -C ./minilibx-linux

fclean: clean
	rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: clean fclean re all
