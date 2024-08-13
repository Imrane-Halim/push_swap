#include "../incs/srcs.h"

void    st_rotate(t_stack **stack)
{
    t_stack *top;
    t_stack *sec;
    t_stack *last;

    top = *stack;
    sec = top->next;
    last = top;
    while (last->next != NULL)
        last = last->next;
    last->next = top;
    top->next = NULL;
    *stack = sec;
}

void    ra(t_stack **a)
{
    st_rotate(a);
}

void    rb(t_stack **b)
{
    st_rotate(b);
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
}