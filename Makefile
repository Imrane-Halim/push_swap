NAME	= 	push_swap

SRC		= 	parse_numbers.c		\
			parse_utils.c		\
			push_swap.c			\
			opirations_1.c		\
			opirations_2.c		\
			opirations_3.c		\
			other_utils.c		\
			push_to_a.c			\
			push_to_b.c 		\
			small_sort.c 		\
			sorting_utils.c 	

CFLAGS	= -Wall -Wextra -Werror
LIBFT	= ./libft/libft.a
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft --silent
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean --silent
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C ./libft fclean --silent
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ)