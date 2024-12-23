CFLAGS	= -Wall -Wextra -Werror
LIBFT	= ./libft/libft.a
NAME	= push_swap
CHECKER	= checker
INC	= ./includes/

COMMON	= 	common/parse_numbers.c		\
		common/parse_utils.c		\
		common/opirations_1.c		\
		common/opirations_2.c		\
		common/opirations_3.c		\
		common/other_utils.c		

MANDATORY = 	mandatory/push_swap.c		\
		mandatory/push_to_a.c		\
		mandatory/push_to_b.c 		\
		mandatory/small_sort.c 		\
		mandatory/sorting_utils.c 	

BONUS	 =	bonus/checker.c 		\
		libft/gnl/get_next_line.c	\
		libft/gnl/get_next_line_utils.c

OBJ	= $(MANDATORY:.c=.o)
BOBJ	= $(BONUS:.c=.o)
COMOBJ 	= $(COMMON:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft --silent

$(NAME): $(OBJ) $(COMOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(COMOBJ) $(LIBFT) -I$(INC) -o $(NAME)

$(CHECKER): $(BOBJ) $(COMOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJ) $(COMOBJ) $(LIBFT) -I$(INC) -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

bonus: $(CHECKER)

clean:
	$(MAKE) -C ./libft clean --silent
	$(RM) $(OBJ) $(COMOBJ) $(BOBJ)

fclean: clean
	$(MAKE) -C ./libft fclean --silent
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJ) $(COMOBJ) $(BOBJ)
