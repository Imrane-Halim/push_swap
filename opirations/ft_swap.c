#include "ops.h"

void    st_swap(t_stack **stack)
{
    long top;
    long ntop;

    if (*stack == NULL || ft_stsize(*stack) < 2)
        return ;
    top = (*stack)->n;
    ntop = (*stack)->next->n;

    ft_stpop(stack);
    ft_stpop(stack);

    ft_stpush(stack, ft_stnew(top));
    ft_stpush(stack, ft_stnew(ntop));
}

void    sa(t_stack **stack)
{
    st_swap(stack);
}

void    sb(t_stack **stack)
{
    st_swap(stack);
}

void    ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
}