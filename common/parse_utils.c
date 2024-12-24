/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/24 20:51:47 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

char	*join_args(int ac, char **av)
{
	int		i;
	char	*s;

	i = 1;
	s = NULL;
	while (i < ac)
	{
		s = ft_strjoin(s, " ");
		s = ft_strjoin(s, av[i]);
		i++;
	}
	return (s);
}

int	is_valid(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_range(char *s)
{
	long	n;

	n = ft_atol(s);
	return (n >= INT_MIN && n <= INT_MAX);
}

void	check_nums(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_valid(av[i]) || !check_range(av[i]))
		{
			i = 0;
			while (av[i])
				free(av[i++]);
			free(av);
			error("Error\n");
		}
		i++;
	}
}
