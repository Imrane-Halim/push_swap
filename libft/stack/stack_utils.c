#include "stack.h"

t_stack	*ft_stnew(long n)
{
	t_stack *new;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
}

void	ft_stpush(t_stack **stack, t_stack *elem)
{
	if (!elem)
		return ;
	if (*stack == NULL) {
		*stack = elem;
		return ;
	}
	elem->next = *stack;
	*stack = elem;
}

void	ft_stpop(t_stack **stack)
{
	t_stack *tmp;
	if (*stack == NULL)
		return ;
	tmp = (*stack)->next;
	*stack = tmp;
	free(tmp);
}

int		ft_stpeek(t_stack *stack)
{
	return (stack->n);
}

int		ft_stsize(t_stack *stack)
{
	int i;
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int		ft_stisempty(t_stack *stack)
{
	return (ft_stsize(stack) == 0);
}
