CFLAGS	= -Wall -Wextra -Werror
LIBFT	= ./libft/libft.a
NAME	= push_swap
CHECKER	= checker

COMMON	=	parse_numbers.c		\
			parse_utils.c		\
			opirations_1.c		\
			opirations_2.c		\
			opirations_3.c		\
			other_utils.c		

SRC		= 	push_swap.c			\
			push_to_a.c			\
			push_to_b.c 		\
			small_sort.c 		\
			sorting_utils.c 	

BONUS	=	checker.c 						\
			libft/gnl/get_next_line.c		\
			libft/gnl/get_next_line_utils.c

OBJ		= $(SRC:.c=.o)
BOBJ	= $(BONUS:.c=.o)
COMOBJ 	= $(COMMON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(COMOBJ)
	$(MAKE) -C ./libft --silent
	$(CC) $(CFLAGS) $(OBJ) $(COMOBJ) $(LIBFT) -o $(NAME)

bonus: $(BOBJ) $(COMOBJ)
	$(MAKE) -C ./libft --silent
	$(CC) $(CFLAGS) $(BOBJ) $(COMOBJ) $(LIBFT) -o $(CHECKER)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean --silent
	$(RM) $(OBJ) $(COMOBJ) $(BOBJ)

fclean: clean
	$(MAKE) -C ./libft fclean --silent
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ) $(COMOBJ) $(BOBJ)