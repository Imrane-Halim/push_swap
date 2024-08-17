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