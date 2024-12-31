/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/31 10:51:05 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		if (i * i > nb)
			return (i - 1);
		i++;
	}
	return (0);
}

t_stack	init_b(t_stack a)
{
	t_stack	b;

	b.stack = malloc(sizeof(int) * a.size);
	if (!b.stack)
	{
		free(a.stack);
		error("Error\n");
	}
	b.size = 0;
	b.top = a.size;
	b.capacity = a.size;
	return (b);
}

int	is_sorted(t_stack a)
{
	int	i;

	i = a.top;
	while (i < a.capacity - 1)
	{
		if (a.stack[i] > a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*new_sorted_array(t_stack *a)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * (a->capacity));
	if (!sorted)
	{
		free(a->stack);
		error("Error\n");
	}
	ft_memcpy(sorted, a->stack, sizeof(int) * (a->capacity));
	return (sorted);
}

void	free_all(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	free(a->sorted);
}
