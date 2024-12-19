#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	*sorted;
	int	top;
	int	size;
	int	capacity;
	int	median_index;
}	t_stack;


//----- parsing functions
void	error(const char *msg);
int     is_valid(char *s);
int     check_range(char *s);
void    check_nums(char **av);
char	*join_args(int ac, char **av);
t_stack	init_a(int ac, char **av);

//----- our sorting rules obviosly
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void    pb(t_stack *b, t_stack *a);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//----- some other utils
void    print_stacks(t_stack a, t_stack b);
t_stack init_b(int a_size);

//-----
int		is_sorted(t_stack a);
void    mysort(t_stack *a);
void    free_all(t_stack *a, t_stack *b);


#endif