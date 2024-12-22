/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opirations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/22 13:26:50 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int print_msg)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	i = 0;
	while (i < a->size - 1)
	{
		tmp = a->stack[i + a->top];
		a->stack[i + a->top] = a->stack[i + a->top + 1];
		a->stack[i + a->top + 1] = tmp;
		i++;
	}
	if (print_msg)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int print_msg)
{
	int	tmp;
	int	i;

	if (b->size < 2)
		return ;
	i = 0;
	while (i < b->size - 1)
	{
		tmp = b->stack[i + b->top];
		b->stack[i + b->top] = b->stack[i + b->top + 1];
		b->stack[i + b->top + 1] = tmp;
		i++;
	}
	if (print_msg)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int print_msg)
{
	int	tmp;
	int	i;

	if (b->size < 2 || a->size < 2)
		return ;
	i = 0;
	while (i < b->size - 1)
	{
		tmp = b->stack[i + b->top];
		b->stack[i + b->top] = b->stack[i + b->top + 1];
		b->stack[i + b->top + 1] = tmp;
		i++;
	}
	i = 0;
	while (i < a->size - 1)
	{
		tmp = a->stack[i + a->top];
		a->stack[i + a->top] = a->stack[i + a->top + 1];
		a->stack[i + a->top + 1] = tmp;
		i++;
	}
	if (print_msg)
		write(1, "rr\n", 3);
}

void	rra(t_stack *a, int print_msg)
{
	int	tmp;
	int	i;

	if (a->size < 2)
		return ;
	i = a->top + a->size - 1;
	while (i > a->top)
	{
		tmp = a->stack[i];
		a->stack[i] = a->stack[i - 1];
		a->stack[i - 1] = tmp;
		i--;
	}
	if (print_msg)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int print_msg)
{
	int	tmp;
	int	i;

	if (b->size < 2)
		return ;
	i = b->top + b->size - 1;
	while (i > b->top)
	{
		tmp = b->stack[i];
		b->stack[i] = b->stack[i - 1];
		b->stack[i - 1] = tmp;
		i--;
	}
	if (print_msg)
		write(1, "rrb\n", 4);
}
