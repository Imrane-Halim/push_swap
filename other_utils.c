#include "push_swap.h"

void    print_stacks(t_stack a, t_stack b)
{
    printf("top --> ");
    for (int i = a.top; i < a.capacity; i++)
        printf("%d ", a.stack[i]);
    printf(" <-- bottom\ntop --> ");
    for (int i = b.top; i < b.capacity; i++)
        printf("%d ", b.stack[i]);
    printf(" <-- bottom\n");
}

t_stack init_b(int a_size)
{
    t_stack b;
    b.stack = malloc(sizeof(int) * a_size);
    b.size = 0;
    b.top = a_size;
    b.capacity = a_size;
    return b;
}

int		is_sorted(t_stack a)
{
	int i;

	i = a.top;
	while (i < a.capacity - 1)
	{
		if (a.stack[i] > a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void    mysort(t_stack *a)
{
    int tmp;
    int i;
    int j;
    int *sorted;

    sorted = malloc(sizeof(int) * (a->capacity));
    ft_memcpy(sorted, a->stack, sizeof(int) * (a->capacity));
    i = 0;
    while (i < a->size - 1)
    {
        j = 0;
        while (j < a->size - i - 1)
        {
            if (sorted[j] > sorted[j + 1])
            {
                tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
    a->sorted = sorted;
}

void    free_all(t_stack *a, t_stack *b)
{
    free(a->stack);
    free(b->stack);
    free(a->sorted);
}