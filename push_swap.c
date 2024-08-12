#include <stdio.h>
#include "opirations/ft_rrotate.c"
//#include "libft/stack/stack_utils.c"

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
    ft_stpush(&a, ft_stnew(1));
    ft_stpush(&a, ft_stnew(2));
    ft_stpush(&a, ft_stnew(3));

    ft_stpush(&b, ft_stnew(7));
    ft_stpush(&b, ft_stnew(8));
    ft_stpush(&b, ft_stnew(9));

    rrr(&a, &b);
    st_print(a, b);

    ft_stclear(&a);
    ft_stclear(&b);
    return 0;
}