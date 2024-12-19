CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = cc

SRC = event.c fractal_utils.c init.c main.c math.c render.c

OBJS = $(SRC:.c=.o)

MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all