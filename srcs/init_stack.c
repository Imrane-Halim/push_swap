#include "../incs/srcs.h"

int	are_num(int ac, char **av)
{
	int	i;

	i = 0;
	while (--ac >= 1)
	{
		i = 0;
		if (av[ac][i] == '-' || av[ac][i] == '+')
		{
			i++;
			if (!av[ac][i])
				return (0);
		}
		while(av[ac][i])
		{
			if (!ft_isdigit(av[ac][i]))
				return (0);
			i++;
		}
	}
	return (1);
}

int are_duplicates(int ac, char **av)
{
	int	i;
	while (--ac >= 1)
	{
		i = 1;
		while (i < ac)
		{
			if (ft_atoi(av[ac]) == ft_atoi(av[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_valid(int ac, char **av)
{
	if (!are_num(ac, av))
		return (0);
	if (are_duplicates(ac, av))
		return (0);
	return (1);
}

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
