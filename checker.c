/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/22 13:19:03 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	close_on_error(t_stack *a, t_stack *b, char *op)
{
	free_all(a, b);
	free(op);
	get_next_line(-1);
	error("Error\n");
}

void	exec_op(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(b, a);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		close_on_error(a, b, op);
}

void	read_operations(t_stack *a, t_stack *b)
{
	char	*tmp;

	tmp = get_next_line(STDIN_FILENO);
	while (tmp)
	{
		exec_op(a, b, tmp);
		tmp = get_next_line(STDIN_FILENO);
		free(tmp);
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
