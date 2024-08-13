#include "incs/srcs.h"
#include <stdio.h>

void	st_print(t_stack *a)
{
	while (a)
	{
		printf("    %ld\n", (a != NULL) ? a->n : 0);
		a = (a != NULL) ? a->next : NULL;
	}
	printf("  ------\n    a\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = st_init(ac, av);

	if (ft_stsize(a) <= 3)
		tiny_sort(&a);
	

	st_print(a);
	ft_stclear(&a);
	ft_stclear(&b);
	return (0);
}
