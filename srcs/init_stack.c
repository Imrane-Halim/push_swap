#include "../libft/stack/stack_utils.c"
#include "../libft/srcs/ft_atoi.c"

t_stack	*st_init(int ac, char **av)
{
	t_stack *stack;
	int		i;

	i = 1;
	stack = NULL;
	while (i < ac)
	{
		ft_stpush(&stack, ft_stnew(ft_atoi(av[i])));
		i++;
	}
	return (stack);
}