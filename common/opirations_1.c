/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opirations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/22 13:28:43 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int print_msg)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->stack[a->top];
		a->stack[a->top] = a->stack[a->top + 1];
		a->stack[a->top + 1] = tmp;
	}
	if (print_msg)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print_msg)
{
	int	tmp;

	if (b->size >= 2)
	{
		tmp = b->stack[b->top];
		b->stack[b->top] = b->stack[b->top + 1];
		b->stack[b->top + 1] = tmp;
	}
	if (print_msg)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int print_msg)
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
	if (print_msg)
		write(1, "ss\n", 3);
}

void	pb(t_stack *b, t_stack *a, int print_msg)
{
	if (a->size == 0)
		return ;
	b->top--;
	b->size++;
	b->stack[b->top] = a->stack[a->top];
	a->top++;
	a->size--;
	if (print_msg)
		write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b, int print_msg)
{
	if (b->size == 0)
		return ;
	a->top--;
	a->size++;
	a->stack[a->top] = b->stack[b->top];
	b->top++;
	b->size--;
	if (print_msg)
		write(1, "pa\n", 3);
}
