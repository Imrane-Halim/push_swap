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

long    ft_atol(char *s)
{
    
	int		i;
	long	res;
	short	sign;

	i = 0;
	while (is_space(s[i]))
		i++;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		sign = 1;
		i++;
	}
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);   
}

int is_in_range(char *n)
{
    if (ft_atoi(n) < ft_atol(n))
        return (0);
    if (ft_atoi(n) > ft_atol(n))
        return (0);
    return (1);
}

int	is_valid(int ac, char **av)
{
	if (!are_num(ac, av))
		return (0);
	if (are_duplicates(ac, av))
		return (0);
    while (--ac >= 1)
    {
        if (!is_in_range(av[ac]))
            return (0);
    }
	return (1);
}
