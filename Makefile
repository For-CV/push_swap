NAME = push_swap
LIBFT = libft/libft.a
SRCS = push_swap.c push_swap_utils.c push_swap_utils1.c push_swap_utils2.c \
       push_swap_utils3.c push_swap_utils4.c push_swap_utils5.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) bonus -C libft

debug: CFLAGS += -g3 -fsanitize=address
debug: re

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re debug
