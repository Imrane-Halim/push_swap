#include "../incs/srcs.h"

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

void    move_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    
    cheapest = get_cheapest(*a);
    if (cheapest->above_median && cheapest->target->above_median)
        rotate_both(a, b, cheapest);
    else if (!(cheapest->above_median) && !(cheapest->target->above_median))
        rrotate_both(a, b, cheapest);
    prep_for_push(a, cheapest, 'a');
    prep_for_push(a, cheapest->target, 'b');
    pb(b, a);
}

void    move_b_to_a(t_stack **a, t_stack **b)
{
    prep_for_push(a, (*b)->target, 'a');
    pa(a, b);
}

void    min_on_top(t_stack **a)
{
    while ((*a)->n != st_min(*a)->n)
    {
        if (st_min(*a)->above_median)
            ra(a);
        else
            rra(a);
    }
}

void    sort(t_stack **a, t_stack **b)
{
    int size;

    size = ft_stsize(*a);
    if (size-- > 3 && !st_sorted(*a))
        pb(b, a);
    if (size-- > 3 && !st_sorted(*a))
        pb(b, a);
    while (size-- > 3 && !st_sorted(*a))
    {
        init_nodes_a(*a, *b);
        move_a_to_b(a, b);
    }
    tiny_sort(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}