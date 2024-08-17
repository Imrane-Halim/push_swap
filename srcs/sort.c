#include "../incs/srcs.h"

t_stack  *st_max(t_stack *stack)
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

t_stack  *st_min(t_stack *stack)
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

t_stack *st_get_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void    tiny_sort(t_stack **stack)
{
    t_stack *mx;

    mx = st_max(*stack);
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
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->n > stack->next->n)
            return (0);
        stack = stack->next;
    }
    return (1);
}


void    sort(t_stack **a, t_stack **b)
{
     (void)a;
     (void)b;
}