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

int is_in_range(char *n)
{
    char min_str[] = "-2147483648";
    char max_str[] = "2147483647";

    if (ft_memcmp(n, min_str, ft_strlen(min_str)) < 0)
        return 0; // too small
    if (ft_memcmp(n, max_str, ft_strlen(max_str)) > 0)
        return 0; // too large
    return 1; // within range
}



int	is_valid(int ac, char **av)
{
	if (!are_num(ac, av))
		return (0);
	if (are_duplicates(ac, av))
		return (0);
	return (1);
}
