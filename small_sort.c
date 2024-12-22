/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/22 13:31:48 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->capacity == 2)
		if (a->stack[a->top] > a->stack[a->capacity - 1])
			sa(a, 1);
	if (a->stack[a->top] > a->stack[a->top + 1]
		&& a->stack[a->capacity - 1] > a->stack[a->top])
		sa(a, 1);
	else if (a->stack[a->top] > a->stack[a->top + 1]
		&& a->stack[a->top + 1] > a->stack[a->capacity - 1])
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (a->stack[a->top] > a->stack[a->capacity - 1]
		&& a->stack[a->top + 1] < a->stack[a->capacity - 1])
		ra(a, 1);
	else if (a->stack[a->top] < a->stack[a->capacity - 1]
		&& a->stack[a->capacity - 1] < a->stack[a->top + 1])
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (a->stack[a->top + 1] > a->stack[a->top]
		&& a->stack[a->top + 1] > a->stack[a->capacity - 1])
		rra(a, 1);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->stack[a->top] == a->sorted[0]
			|| a->stack[a->top] == a->sorted[1])
			pb(b, a, 1);
		else
			ra(a, 1);
	}
	sort_3(a);
	if (b->stack[b->top] < b->stack[b->capacity - 1])
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	if (a->stack[a->top] > a->stack[a->top + 1])
		sa(a, 1);
}
