/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opirations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/21 14:47:29 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->stack[a->top];
		a->stack[a->top] = a->stack[a->top + 1];
		a->stack[a->top + 1] = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size >= 2)
	{
		tmp = b->stack[b->top];
		b->stack[b->top] = b->stack[b->top + 1];
		b->stack[b->top + 1] = tmp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->stack[a->top];
		a->stack[a->top] = a->stack[a->top + 1];
		a->stack[a->top + 1] = tmp;
	}
	if (b->size >= 2)
	{
		tmp = b->stack[b->top];
		b->stack[b->top] = b->stack[b->top + 1];
		b->stack[b->top + 1] = tmp;
	}
	write(1, "ss\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	if (a->size == 0)
		return ;
	b->top--;
	b->size++;
	b->stack[b->top] = a->stack[a->top];
	a->top++;
	a->size--;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	a->top--;
	a->size++;
	a->stack[a->top] = b->stack[b->top];
	b->top++;
	b->size--;
	write(1, "pa\n", 3);
}
