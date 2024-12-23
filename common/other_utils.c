/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/20 10:50:09 by ihalim           ###   ########.fr       */
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

t_stack	init_b(int a_size)
{
	t_stack	b;

	b.stack = malloc(sizeof(int) * a_size);
	b.size = 0;
	b.top = a_size;
	b.capacity = a_size;
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

void	mysort(t_stack *a)
{
	int	tmp;
	int	i;
	int	j;
	int	*sorted;

	sorted = malloc(sizeof(int) * (a->capacity));
	ft_memcpy(sorted, a->stack, sizeof(int) * (a->capacity));
	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	a->sorted = sorted;
}

void	free_all(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	free(a->sorted);
}
