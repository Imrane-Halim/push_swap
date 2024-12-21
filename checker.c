/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/21 14:24:28 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

enum e_op is_valid_op(char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		return (SA);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		return (SB);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		return (SS);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		return (PA);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		return (PB);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		return (RA);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		return (RB);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		return (RR);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		return (RRA);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		return (RRB);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		return (RRR);	
	return (INVALID);
}

void	exec_op(t_stack *a, t_stack *b, enum e_op op)
{
	if (op == SA)
		sa(a);
	else if (op == SB)
		sb(b);
	else if (op == SS)
		ss(a, b);
	else if (op == PA)
		pa(a, b);
	else if (op == PB)
		pb(a, b);
	else if (op == RA)
		ra(a);
	else if (op == RB)
		rb(b);
	else if (op == RR)
		rr(a, b);
	else if (op == RRA)
		rra(a);
	else if (op == RRB)
		rrb(b);
	else if (op == RRR)
		rrr(a, b);	
}
void	read_operations(t_stack *a, t_stack *b)
{
	char		*tmp;
	enum e_op	op;
	
	tmp = get_next_line(STDIN_FILENO);
	while (tmp)
	{
		op = is_valid_op(tmp);
		if (op == INVALID)
		{
			get_next_line(-1);
			free(tmp);
			free_all(a, b);
			error("Error\n");
		}
		else
			exec_op(a, b, op);
		free(tmp);
		tmp = get_next_line(STDIN_FILENO);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	
	if (ac < 2)
		return (EXIT_SUCCESS);
	
	a = init_a(ac, av);
	b = init_b(a.size);
	read_operations(&a, &b);
	if (is_sorted(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}