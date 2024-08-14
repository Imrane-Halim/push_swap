#include "../incs/srcs.h"

int	is_sorted(int ac, char **av)
{
	while (--ac >= 1)
	{
		if (ft_atoi(av[ac]) < ft_atoi(av[ac - 1]))
			return (0);
	}
	return (1);
}

t_stack	*st_init(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*tmp;

	if (!is_valid(ac, av))
		error_handler();
	if (ac < 3 || is_sorted(ac, av))
		exit(0);
	stack = NULL;
	while (--ac >= 1)
	{
		tmp = ft_stnew(ft_atoi(av[ac]));
		if (!tmp)
			error_handler();
		ft_stpush(&stack, tmp);
	}
	return (stack);
}
