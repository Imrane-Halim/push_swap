#include "incs/srcs.h"
#include <stdio.h>

void	st_print(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		printf("    %d           %d\n", (a != NULL) ? a->n : 0, (b != NULL) ? b->n : 0);
		a = (a != NULL) ? a->next : NULL;
		b = (b != NULL) ? b->next : NULL;
	}
	printf("  ------     ------\n    a           b\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = st_init(ac, av);
	
	st_print(a, b);
	if (ft_stsize(a) <= 3)
		tiny_sort(&a);
	else
		sort(&a, &b);

	st_print(a, b);
	ft_stclear(&a);
	ft_stclear(&b);
	return (0);
}
