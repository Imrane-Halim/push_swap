#include "../incs/srcs.h"

void    st_rrotate(t_stack **stack)
{
    t_stack *pre_last;
    t_stack *last;
    t_stack *top;

    top = (*stack);
    pre_last = top;
    while (pre_last->next->next != NULL)
        pre_last = pre_last->next;
    last = pre_last->next;
    pre_last->next = NULL;
    last->next = top;

    *stack = last;
}

void    rra(t_stack **a)
{
    st_rrotate(a);
}

void    rrb(t_stack **b)
{
    st_rrotate(b);
}

void    rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
}