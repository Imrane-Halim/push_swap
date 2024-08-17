#include "../incs/srcs.h"

void    set_target_b(t_stack *a, t_stack *b)
{
    t_stack *current;
    t_stack *target;
    long    best_match_index;

    while (b)
    {
        best_match_index = LONG_MIN;
        current = a;
        while (current)
        {
            if (current->n > b->n && current->n < best_match_index)
            {
                best_match_index = current->n;
                target = current;
            }
            current = current->next;
        }
        if (best_match_index == LONG_MIN)
            b->target = st_max(a);
        else
            b->target = target;
        b = b->next;
    }
}

void    init_nodes_b(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}
