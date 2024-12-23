/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/23 11:19:53 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	count_nums(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	check_duplicates(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				error("Error\n");
			}
			j++;
		}
		i++;
	}
}

void	init_array(t_stack *a, char **args)
{
	int	i;

	a->stack = malloc(sizeof(int) * (count_nums(args)));
	i = 0;
	while (args[i])
	{
		a->stack[i] = ft_atoi(args[i]);
		free(args[i]);
		i++;
	}
	a->top = 0;
	a->size = i;
	a->capacity = i;
	free(args);
	check_duplicates(a->stack, a->size);
	mysort(a);
}

t_stack	init_a(int ac, char **av)
{
	char	*s;
	char	**args;
	t_stack	a;

	s = join_args(ac, av);
	if (!s)
		error("Error\n");
	args = ft_split(s, ' ');
	if (!args)
	{
		free(s);
		error("Error\n");
	}
	free(s);
	check_nums(args);
	init_array(&a, args);
	return (a);
}
