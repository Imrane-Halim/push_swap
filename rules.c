#include "push_swap.h"

void    sa(t_stack *a)
{
    int tmp;
    if (a->size >= 2)
    {
        tmp = a->stack[a->top];
        a->stack[a->top] = a->stack[a->top + 1];
        a->stack[a->top + 1] = tmp;
    }
    write(1, "sa\n", 3);
}

void    sb(t_stack *b)
{
    int tmp;
    if (b->size >= 2)
    {
        tmp = b->stack[b->top];
        b->stack[b->top] = b->stack[b->top + 1];
        b->stack[b->top + 1] = tmp;
    }
    write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b)
{
    int tmp;
    if (a->size >= 2)
    {
        tmp = a->stack[a->top];
        a->stack[a->top] = a->stack[a->top + 1];
        a->stack[a->top + 1] = tmp;
    }
    if (b->size >= 2)
    {
        tmp = b->stack[b->top];
        b->stack[b->top] = b->stack[b->top + 1];
        b->stack[b->top + 1] = tmp;
    }
    write(1, "ss\n", 3);
}

void    pb(t_stack *b, t_stack *a)
{
    if (a->size == 0)
        return ;
    b->top--;
    b->size++;
    b->stack[b->top] = a->stack[a->top];
    a->top++;
    a->size--;
    write(1, "pb\n", 3);
}

void    pa(t_stack *a, t_stack *b)
{
    if (b->size == 0)
        return ;
    a->top--;
    a->size++;
    a->stack[a->top] = b->stack[b->top];
    b->top++;
    b->size--;
    write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
    int tmp;
    int i;

    if (a->size < 2)
        return ;
    i = 0;
    while (i < a->size - 1)
    {
        tmp = a->stack[i + a->top];
        a->stack[i + a->top] = a->stack[i + a->top + 1];
        a->stack[i + a->top + 1] = tmp;
        i++;
    }
    write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
    int tmp;
    int i;

    if (b->size < 2)
        return ;
    i = 0;
    while (i < b->size - 1)
    {
        tmp = b->stack[i + b->top];
        b->stack[i + b->top] = b->stack[i + b->top + 1];
        b->stack[i + b->top + 1] = tmp;
        i++;
    }
    write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    int tmp;
    int i;

    if (b->size < 2 || a->size < 2)
        return ;
    i = 0;
    while (i < b->size - 1)
    {
        tmp = b->stack[i + b->top];
        b->stack[i + b->top] = b->stack[i + b->top + 1];
        b->stack[i + b->top + 1] = tmp;
        i++;
    }
    i = 0;
    while (i < a->size - 1)
    {
        tmp = a->stack[i + a->top];
        a->stack[i + a->top] = a->stack[i + a->top + 1];
        a->stack[i + a->top + 1] = tmp;
        i++;
    }
    write(1, "rr\n", 3);
}

void    rra(t_stack *a)
{
    int tmp;
    int i;

    if (a->size < 2)
        return ;
    
    i = a->top + a->size - 1;
    while (i > a->top)
    {
        tmp = a->stack[i];
        a->stack[i] = a->stack[i - 1];
        a->stack[i - 1] = tmp;
        i--;
    }
    write(1, "rra\n", 4);   
}

void    rrb(t_stack *b)
{
    int tmp;
    int i;

    if (b->size < 2)
        return ;
    i = b->top + b->size - 1;
    while (i > b->top)
    {
        tmp = b->stack[i];
        b->stack[i] = b->stack[i - 1];
        b->stack[i - 1] = tmp;
        i--;
    }
    write(1, "rrb\n", 4);   
}

void    rrr(t_stack *a, t_stack *b)
{
    int tmp;
    int i;

    if (a->size < 2 || b->size < 2)
        return ;
    
    i = a->top + a->size - 1;
    while (i > a->top)
    {
        tmp = a->stack[i];
        a->stack[i] = a->stack[i - 1];
        a->stack[i - 1] = tmp;
        i--;
    }
    i = b->top + b->size - 1;
    while (i > b->top)
    {
        tmp = b->stack[i];
        b->stack[i] = b->stack[i - 1];
        b->stack[i - 1] = tmp;
        i--;
    }
    write(1, "rrr\n", 4);
}
