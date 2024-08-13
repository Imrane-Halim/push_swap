#include "../incs/srcs.h"

void st_rotate(t_stack **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    t_stack *top = *stack;
    t_stack *sec = top->next;
    t_stack *last = top;
    while (last->next != NULL)
        last = last->next;
    last->next = top;
    top->next = NULL;
    *stack = sec;
}

void	ra(t_stack **a)
{
	st_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	st_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	st_rotate(a);
	st_rotate(b);
	write(1, "rr\n", 3);
}
