#include "../incs/srcs.h"

t_stack  *max(t_stack *stack)
{
    t_stack *max;

    max = stack;
    while(stack)
    {
        if (stack->n > max->n)
            max = stack;
        stack = stack->next;
    }
    return (max);
}

t_stack  *min(t_stack *stack)
{
    t_stack *min;

    min = stack;
    while(stack)
    {
        if (stack->n < min->n)
            min = stack;
        stack = stack->next;
    }
    return (min);
}

void    tiny_sort(t_stack **stack)
{
    t_stack *mx;

    mx = max(*stack);
    if (ft_stsize(*stack) > 2)
    {
        if (*stack == mx)
            ra(stack);
        else if ((*stack)->next == mx)
            rra(stack);
    }
    if ((*stack)->n > (*stack)->next->n)
        sa(stack);
}

int     st_sorted(t_stack *stack)
{
    while (stack && stack->next != NULL)
    {
        if (stack->n > stack->next->n)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void    sort_until_3(t_stack **a, t_stack **b)
{
    while (ft_stsize(*a) > 3)
    {
        if ((*a)->n < (*a)->next->n && (*b)->n > (*b)->next->n)
        {
            ss(a, b);
            pb(b, a);
        }
        else if ((*a)->n < (*a)->next->n)
        {
            sa(a);
            pb(b, a);
        }
        if ((*b)->n > (*b)->next->n)
            sb(b);
        
    }
}

void    sort(t_stack **a, t_stack **b)
{
    sort_until_3(a, b);
}