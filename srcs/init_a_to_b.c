#include "../incs/srcs.h"

void    current_index(t_stack *stack)
{
    int index;
    int median;

    if (!stack)
        return ;
    index = 0;
    median = ft_stsize(stack) / 2;
    while (stack)
    {
        stack->index = index;
        if (index <= median)
            stack->above_median = 1;
        else
            stack->above_median = 0;
        stack = stack->next;
        index++;
    }
}

void    set_target_a(t_stack *a, t_stack *b)
{
    t_stack *current;
    t_stack *target;
    long    best_match_index;

    while (a)
    {
        best_match_index = LONG_MIN;
        current = b;
        while (current)
        {
            if (current->n < a->n && current->n > best_match_index)
            {
                best_match_index = current->n;
                target = current;
            }
            current = current->next;
        }
        if (best_match_index == LONG_MIN)
            a->target = st_max(b);
        else
            a->target = target;
        a = a->next;
    }
}

void    cost_analysis_a(t_stack *a, t_stack *b)
{
    int a_size;
    int b_size;

    a_size = ft_stsize(a);
    b_size = ft_stsize(b);
    while (a)
    {
        a->cost = a->index;
        if (!(a->above_median))
            a->cost = a_size - (a->index);
        if (a->target->above_median)
            a->cost += a->target->index;
        else
            a->cost += b_size - (a->target->index);
        a = a->next;
    }
}

void    set_cheapest(t_stack *stack)
{
    long    cheapest;
    t_stack *cheapest_target;
    if (!stack)
        return ;
    cheapest = LONG_MAX;
    while (stack)
    {
        if (stack->cost < cheapest)
        {
            cheapest = stack->cost;
            cheapest_target = stack;
        }
        stack = stack->next;
    }
    cheapest_target->cheapest = 1;
}

void    init_nodes_a(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis_a(a, b);
    set_cheapest(a);
}