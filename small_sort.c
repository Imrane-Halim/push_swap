/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/20 10:49:26 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->capacity == 2)
		if (a->stack[a->top] > a->stack[a->capacity - 1])
			sa(a);
	if (a->stack[a->top] > a->stack[a->top + 1]
		&& a->stack[a->capacity - 1] > a->stack[a->top])
		sa(a);
	else if (a->stack[a->top] > a->stack[a->top + 1]
		&& a->stack[a->top + 1] > a->stack[a->capacity - 1])
	{
		sa(a);
		rra(a);
	}
	else if (a->stack[a->top] > a->stack[a->capacity - 1]
		&& a->stack[a->top + 1] < a->stack[a->capacity - 1])
		ra(a);
	else if (a->stack[a->top] < a->stack[a->capacity - 1]
		&& a->stack[a->capacity - 1] < a->stack[a->top + 1])
	{
		sa(a);
		ra(a);
	}
	else if (a->stack[a->top + 1] > a->stack[a->top]
		&& a->stack[a->top + 1] > a->stack[a->capacity - 1])
		rra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->stack[a->top] == a->sorted[0]
			|| a->stack[a->top] == a->sorted[1])
			pb(b, a);
		else
			ra(a);
	}
	sort_3(a);
	if (b->stack[b->top] < b->stack[b->capacity - 1])
		sb(b);
	pa(a, b);
	pa(a, b);
	if (a->stack[a->top] > a->stack[a->top + 1])
		sa(a);
}
