/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/20 10:49:41 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_half_to_a(t_stack *a, t_stack *b, int num, int *rank)
{
	(*rank)--;
	while (b->stack[b->top] != num)
		rb(b);
	pa(a, b);
}

static void	bot_half_to_a(t_stack *a, t_stack *b, int num, int *rank)
{
	(*rank)--;
	while (b->stack[b->top] != num)
		rrb(b);
	pa(a, b);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	int	top;
	int	bot;
	int	rank;

	rank = a->capacity;
	while (b->size > 0)
	{
		top = b->top;
		bot = b->top + b->size - 1;
		while (top <= bot && rank > 0)
		{
			if (get_rank(b->stack[top], a->sorted, a->capacity) == rank)
			{
				top_half_to_a(a, b, b->stack[top], &rank);
				break ;
			}
			if (get_rank(b->stack[bot], a->sorted, a->capacity) == rank)
			{
				bot_half_to_a(a, b, b->stack[bot], &rank);
				break ;
			}
			top++;
			bot--;
		}
	}
}
