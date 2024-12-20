/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/20 10:49:21 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rank(int num, int *sorted, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (num == sorted[i])
			return (i + 1);
		i++;
	}
	return (-1);
}

int	get_pos(int num, t_stack *stk)
{
	int	i;

	i = stk->top;
	while (i < stk->capacity)
	{
		if (num == stk->stack[i])
			return (i);
		i++;
	}
	return (-1);
}

void	sort_other(t_stack *a, t_stack *b)
{
	push_to_b(a, b);
	push_to_a(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->capacity <= 3)
		sort_3(a);
	else if (a->capacity <= 5)
		sort_5(a, b);
	else
		sort_other(a, b);
}
