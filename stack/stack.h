#include <stdlib.h>

typedef struct s_stack
{
	int			n;
	int			index;
	int			cost;
	int			above_median;
	int			cheapest;

	struct s_stack  *target;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_stnew(int n);
void				ft_stpush(t_stack **stack, t_stack *content);
void				ft_stpop(t_stack **stack);
int				ft_stpeek(t_stack *stack);
int					ft_stisempty(t_stack *stack);
int					ft_stsize(t_stack *stack);
void				ft_stclear(t_stack **stack);
