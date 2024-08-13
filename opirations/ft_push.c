#include "../incs/srcs.h"

void    st_push(t_stack **dst, t_stack **src)
{
    if (*src == NULL)
        return ;
    ft_stpush(dst, ft_stnew(ft_stpeek(*src)));
    ft_stpop(src);
}

void    pa(t_stack **a, t_stack **b)
{
    st_push(a, b);
}

void    pb(t_stack **b, t_stack **a)
{
    st_push(b, a);
}