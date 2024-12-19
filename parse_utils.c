#include "./push_swap.h"

void	error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
char *join_args(int ac, char **av)
{
    int i = 1;
    char *s = NULL;

    while (i < ac)
    {
        s = ft_strjoin(s, " ");
        s = ft_strjoin(s, av[i]);
        i++;
    }
    return s;
}

int     is_valid(char *s)
{
    int i = 0;
    if (s[i] == '\0')
        return (0);
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

int     check_range(char *s)
{
    long n;
    n = ft_atol(s);
    return (n >= INT_MIN && n <= INT_MAX);
}
void    check_nums(char **av)
{
    int i = 0;
    while (av[i])
    {
        if (!is_valid(av[i]) || !check_range(av[i]))
            error("Error\n");
        i++;
    }
}
