/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:31:53 by ihalim            #+#    #+#             */
/*   Updated: 2024/12/23 15:10:22 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	*sorted;
	int	top;
	int	size;
	int	capacity;
}	t_stack;

//----- parsing functions
void	error(const char *msg);
int		is_valid(char *s);
int		check_range(char *s);
void	check_nums(char **av);
char	*join_args(int ac, char **av);
t_stack	init_a(int ac, char **av);

//----- sorting rules obviosly
void	sa(t_stack *a, int print_msg);
void	sb(t_stack *b, int print_msg);
void	ss(t_stack *a, t_stack *b, int print_msg);

void	pa(t_stack *a, t_stack *b, int print_msg);
void	pb(t_stack *b, t_stack *a, int print_msg);

void	ra(t_stack *a, int print_msg);
void	rb(t_stack *b, int print_msg);
void	rr(t_stack *a, t_stack *b, int print_msg);

void	rra(t_stack *a, int print_msg);
void	rrb(t_stack *b, int print_msg);
void	rrr(t_stack *a, t_stack *b, int print_msg);

//----- sorting utils
int		get_rank(int num, int *sorted, int len);
int		get_pos(int num, t_stack *stk);

void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
void	push_to_a(t_stack *a, t_stack *b);
void	push_to_b(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);

//----- some other utils
int		ft_sqrt(int nb);
t_stack	init_b(int a_size);
int		is_sorted(t_stack a);
void	mysort(t_stack *a);
void	free_all(t_stack *a, t_stack *b);

#endif