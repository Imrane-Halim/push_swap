#include <stdlib.h>

typedef struct s_stack
{
	long	n;
	struct s_stack *next;
} t_stack;

t_stack	*ft_stnew(long n);
void	ft_stpush(t_stack **stack, t_stack *content);
void	ft_stpop(t_stack **stack);
long 	ft_stpeek(t_stack *stack);
int		ft_stisempty(t_stack *stack);
int		ft_stsize(t_stack *stack);
void	ft_stclear(t_stack **stack);
