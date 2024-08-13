#include "../libft/srcs/libft.h"
#include "../stack/stack.h"
#include <stdlib.h>
#include <unistd.h>

// push the top elem of a stack to another
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// swap the top 2 elems
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **a, t_stack **b);

// rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

t_stack	*st_init(int ac, char **av);
void	error_handler(void);

// sorting stuff
void    tiny_sort(t_stack **stack);