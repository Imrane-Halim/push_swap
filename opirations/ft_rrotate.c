#include "../incs/srcs.h"

void	st_rrotate(t_stack **stack)
{
	t_stack	*pre_last;
	t_stack	*last;
	t_stack	*top;

	if (*stack == NULL || (*stack)->next == NULL)
        return ;
		
	top = (*stack);
	pre_last = top;
	while (pre_last->next->next != NULL)
		pre_last = pre_last->next;
	last = pre_last->next;
	pre_last->next = NULL;
	last->next = top;
	*stack = last;
}

void	rra(t_stack **a)
{
	st_rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	st_rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	st_rrotate(a);
	st_rrotate(b);
	write(1, "rrr\n", 4);
}

void    rrotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}