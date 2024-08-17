#include "../incs/srcs.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = st_init(ac, av);
	if (ft_stsize(a) <= 3)
		tiny_sort(&a);
	else
		sort(&a, &b);
	
	ft_stclear(&a);
	return (0);
}
