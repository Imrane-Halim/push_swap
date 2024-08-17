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
