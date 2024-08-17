#include "../libft/srcs/libft.h"
#include "../stack/stack.h"
#include <limits.h>

// input validation
int	are_num(int ac, char **av);
int are_duplicates(int ac, char **av);
int is_in_range(char *n);
int	is_valid(int ac, char **av);


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
void    rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

// reverse rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void    rrotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

t_stack	*st_init(int ac, char **av);
void	error_handler(void);

// sorting stuff
t_stack  *st_max(t_stack *stack);
t_stack  *st_min(t_stack *stack);
t_stack *st_get_last(t_stack *stack);
int     is_sorted(int ac, char **av);
void    tiny_sort(t_stack **stack);
int     st_sorted(t_stack *stack);
void    sort(t_stack **a, t_stack **b);
void    current_index(t_stack *stack);
void    init_nodes_a(t_stack *a, t_stack *b);
void    init_nodes_b(t_stack *a, t_stack *b);
void    prep_for_push(t_stack **stack, t_stack *top, char st);
t_stack *get_cheapest(t_stack *stack);