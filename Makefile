CC = cc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -MD -MP

INCLUDE_DIR = include

IFLAGS = \
		 -I $(INCLUDE_DIR) \
		 -I $(LIBFT_DIR)/$(INCLUDE_DIR) \
		 -I $(MLX_DIR)

LFLAGS = -Lmlx_linux -lXext -lX11

SRC =  main.c \
		parsing.c \
		bresenham.c \

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src

LIBS_DIR = libs

LIBFT_DIR = $(LIBS_DIR)/libft

MLX_DIR = $(LIBS_DIR)/minilibx-linux

LIBFT = libft.a

MLX = libmlx.a

NAME = fdf

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	$(CC) -o $(NAME) $(CFLAGS) $(LFLAGS)  $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)
	mkdir -p .build
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR) $(LIBFT)

$(MLX_DIR)/$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR) all

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: FORCE
FORCE:

.PHONY: re
re: fclean
	$(MAKE) all