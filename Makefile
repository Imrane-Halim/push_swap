CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INC			= incs

OPS_SRC		= $(wildcard opirations/*.c)
SRCS		= $(wildcard srcs/*.c)
STACK		= $(wildcard stack/*.c)

OPS_OBJS	= $(OPS_SRC:.c=.o)
SRC_OBJS	= $(SRCS:.c=.o)
STACK_OBJS	= $(STACK:.c=.o)

NAME		= push_swap
LIBFT		= ./libft/libft.a

all: $(NAME)

$(NAME): $(OPS_OBJS) $(SRC_OBJS) $(STACK_OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OPS_OBJS) $(SRC_OBJS) $(STACK_OBJS) $(LIBFT) $(NAME).c  -I INC -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OPS_OBJS) $(SRC_OBJS) $(STACK_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all