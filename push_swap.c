#include <stdio.h>
#include "srcs/init_stack.c"

void    st_print(t_stack *a, t_stack *b) 
{
    while (a || b)
    {
        printf("  |  %d  | |  %d  |\n", (a != NULL) ? a->n : 0, (b != NULL) ? b->n : 0);
        a = (a != NULL) ? a->next : NULL;
        b = (b != NULL) ? b->next : NULL;
    }
    printf("  |-----| |-----|\n");
}

int main(int ac, char **av)
{
    t_stack *a = NULL, *b = NULL;
    a = st_init(ac, av);
    st_print(a, b);
    return 0;
}