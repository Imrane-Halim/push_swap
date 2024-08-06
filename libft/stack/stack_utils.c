#include "stack.h"

t_stack		*ft_stnew(void)
{
	t_stack *stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->elem = NULL;
	return (stack);
}

void		ft_stpush(t_stack *stack, void *content)
{
	t_list *new_elem = ft_lstnew(content);
	if (!new_elem)
		return ;
	ft_lstadd_front(&stack->elem, new_elem);
}

void		*ft_stpop(t_stack *stack)
{
	if (!stack)
		return NULL;
	t_list *top = stack->elem;
	void	*content = top->content;
	stack->elem = top->next;
	free(top);
	return (content);
}

void		*ft_stpeek(t_stack *stack)
{
	if (!stack || !stack->elem)
		return (NULL);
	return (stack->elem->content);
}

int			ft_stisempty(t_stack *stack)
{
	return (!stack->elem);
}

int			ft_stsize(t_stack *stack)
{
	return (ft_lstsize(stack->elem));
}

void		ft_stclear(t_stack *stack, void (*del)(void *))
{
	ft_lstclear(&stack->elem, del);
	free(stack);
}
