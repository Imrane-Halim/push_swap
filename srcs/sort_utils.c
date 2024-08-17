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

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void    prep_for_push(t_stack **stack, t_stack *top, char st)
{
    while (*stack != top)
    {
        if (st == 'a')
        {
            if (top->above_median)
                ra(stack);
            else
                rra(stack);
            write(1, "aaaa", 4);
        }
        else if (st == 'b')
        {
            if (top->above_median)
                rb(stack);
            else
                rrb(stack);
            write(1, "bbbb", 4);
        }
    }
}