/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opirations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/22 13:26:56 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b, int print_msg)
{
	int	tmp;
	int	i;

	if (a->size < 2 || b->size < 2)
		return ;
	i = a->top + a->size - 1;
	while (i > a->top)
	{
		tmp = a->stack[i];
		a->stack[i] = a->stack[i - 1];
		a->stack[i - 1] = tmp;
		i--;
	}
	i = b->top + b->size - 1;
	while (i > b->top)
	{
		tmp = b->stack[i];
		b->stack[i] = b->stack[i - 1];
		b->stack[i - 1] = tmp;
		i--;
	}
	if (print_msg)
		write(1, "rrr\n", 4);
}
