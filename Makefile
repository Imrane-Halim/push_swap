stack_test: stack/main.c stack/stack_utils.c libft/libft.a
	cc -L libft stack/main.c stack/stack_utils.c -lft
