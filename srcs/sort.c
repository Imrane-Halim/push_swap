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

int	is_sorted(int ac, char **av)
{
	while (--ac >= 1)
	{
		if (ft_atoi(av[ac]) < ft_atoi(av[ac - 1]))
			return (0);
	}
	return (1);
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

