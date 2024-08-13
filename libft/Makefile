NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard srcs/*.c)
OBJS	= $(SRCS:.c=.o)
BONUS 	= $(wildcard srcs/*_bonus.c)
BOBJS 	= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BOBJS)
	ar rcs $(NAME) $(OBJS) $(BOBJS)

%.o: %.c 
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f srcs/*.o stack/*.o 

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
