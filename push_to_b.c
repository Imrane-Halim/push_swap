/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/20 10:49:35 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_rb(t_stack *a, t_stack *b, int num)
{
	if (get_pos(num, a) <= (a->size / 2 + a->top))
	{
		while (num != a->stack[a->top])
			ra(a);
		pb(b, a);
		rb(b);
	}
	else
	{
		while (num != a->stack[a->top])
			rra(a);
		pb(b, a);
		rb(b);
	}
}

static void	just_push(t_stack *a, t_stack *b, int num)
{
	if (get_pos(num, a) <= (a->size / 2 + a->top))
	{
		while (num != a->stack[a->top])
			ra(a);
		pb(b, a);
	}
	else
	{
		while (num != a->stack[a->top])
			rra(a);
		pb(b, a);
	}
}

static void	reset(int *min, int *max, int *i, int top)
{
	(*min)++;
	(*max)++;
	*i = top;
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	rank;
	int	i;

	min = 1;
	max = ft_sqrt(a->capacity) + a->capacity / 500 + 5;
	i = a->top;
	while (i < a->capacity)
	{
		rank = get_rank(a->stack[i], a->sorted, a->capacity);
		if (rank < min)
		{
			rotate_rb(a, b, a->stack[i]);
			reset(&min, &max, &i, a->top);
			continue ;
		}
		else if (rank >= min && rank <= max)
		{
			just_push(a, b, a->stack[i]);
			reset(&min, &max, &i, a->top);
			continue ;
		}
		i++;
	}
}
