#include "../srcs/libft.h"

typedef struct s_stack
{
	t_list *elem;
} t_stack;

//////////////////////////////////////////////////
t_stack	*ft_stnew(void);
void	ft_stpush(t_stack *stack, void *content);
void	*ft_stpop(t_stack *stack);
void	*ft_stpeek(t_stack *stack);
int		ft_stisempty(t_stack *stack);
int		ft_stsize(t_stack *stack);
void	ft_stclear(t_stack *stack, void (*del)(void *del));
