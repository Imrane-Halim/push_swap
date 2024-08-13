#include "incs/srcs.h"
#include <stdio.h>

void	st_print(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		printf("  |  %ld  | |  %ld  |\n", (a != NULL) ? a->n : 0,
				(b != NULL) ? b->n : 0);
		a = (a != NULL) ? a->next : NULL;
		b = (b != NULL) ? b->next : NULL;
	}
	printf("  |-----| |-----|\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = st_init(ac, av);

	st_print(a, b);
	ft_stclear(&a);
	ft_stclear(&b);
	return (0);
}
