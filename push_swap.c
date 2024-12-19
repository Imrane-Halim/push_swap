#include "push_swap.h"
#include <math.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		if (i * i > nb)
			return (i - 1);
		i++;
	}
	return (0);
}



void	sort_3(t_stack *a)
{
	if (a->capacity == 2)
		if (a->stack[a->top] > a->stack[a->capacity - 1])
			sa(a);
	if (	a->stack[a->top] > a->stack[a->top + 1]
		&&  a->stack[a->capacity - 1] > a->stack[a->top])
		sa(a);
	else if (a->stack[a->top] > a->stack[a->top + 1]
		&&   a->stack[a->top + 1] > a->stack[a->capacity - 1])
	{
		sa(a);
		rra(a);
	}
	else if (a->stack[a->top] > a->stack[a->capacity - 1]
		&& a->stack[a->top + 1] < a->stack[a->capacity - 1])
		ra(a);
	else if (a->stack[a->top] < a->stack[a->capacity - 1]
		&& a->stack[a->capacity - 1] < a->stack[a->top + 1])
	{
		sa(a);
		ra(a);
	}
	else if (a->stack[a->top + 1] > a->stack[a->top]
		&& a->stack[a->top + 1] > a->stack[a->capacity - 1])
		rra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->stack[a->top] == a->sorted[0] || a->stack[a->top] == a->sorted[1])
			pb(b, a);
		else
			ra(a);
	}
	sort_3(a); 
	if (b->stack[b->top] < b->stack[b->capacity - 1])
		sb(b);
	pa(a, b);
	pa(a, b);
	if (a->stack[a->top] > a->stack[a->top + 1])
		sa(a);
}





int	 get_rank(int num, int *sorted, int len)
{
	int i;

	i = 0;
	while (i <= len)
	{
		if (num == sorted[i])
			return (i + 1);
		i++;
	}
	return (-1);
}

int get_pos(int num, t_stack *stk)
{
	int i;

	i = stk->top;
	while (i < stk->capacity)
	{
		if (num == stk->stack[i])
			return (i);
		i++;
	}
	return (-1);
}

void rotate_rb(t_stack *a, t_stack *b, int num)
{
	if (get_pos(num, a) <= (a->size / 2 + a->top)) 
	{
		while (num != a->stack[a->top])
			ra(a);
		pb(b, a);
		rb(b);
	}
	else
	{
		while (num != a->stack[a->top])
			rra(a);
		pb(b, a);
		rb(b);
	}
}

void just_push(t_stack *a, t_stack *b, int num)
{
	if (get_pos(num, a) <= (a->size / 2 + a->top))
	{
		while (num != a->stack[a->top])
			ra(a);
		pb(b, a);
	}
	else
	{
		while (num != a->stack[a->top])
			rra(a);
		pb(b, a);
	}
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int min;
	int max;
	int num;
	int rank;
	int i;

	min = 1;
	max = ft_sqrt(a->capacity) + a->capacity / 500 + 5;
	i = a->top;
	while (i < a->capacity)
	{
		num = a->stack[i];
		rank = get_rank(num, a->sorted, a->capacity);
		if (rank < min)
		{
			rotate_rb(a, b, num);
			min++;
			max++;
			i = a->top;
			continue;
		}
		else if (rank >= min && rank <= max)
		{
			just_push(a, b, num);
			min++;
			max++;
			i = a->top;
			continue;
		}
		i++;
	}
}




void	top_half_to_a(t_stack *a, t_stack *b, int num)
{
	while (b->stack[b->top] != num)
		rb(b);
	pa(a, b);
}

void	bot_half_to_a(t_stack *a, t_stack *b, int num)
{
	while (b->stack[b->top] != num)
		rrb(b);
	pa(a, b);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	int top;
	int bottom;
	int target_rank;
	int top_num;
	int bot_num;

	target_rank = a->capacity;

	while (b->size > 0)
	{
		top = b->top;
		bottom = b->top + b->size - 1;

		while (top <= bottom)
		{
			top_num = b->stack[top];
			bot_num = b->stack[bottom];

			if (get_rank(top_num, a->sorted, a->capacity) == target_rank)
			{
				top_half_to_a(a, b, top_num);
				target_rank--;
				break;
			}
			if (get_rank(bot_num, a->sorted, a->capacity) == target_rank)
			{
				bot_half_to_a(a, b, bot_num);
				target_rank--;
				break;
			}
			top++;
			bottom--;
		}
	}
}





void	sort_other(t_stack *a, t_stack *b)
{
	push_to_b(a, b);
	push_to_a(a, b);
}
void	sort(t_stack *a, t_stack *b)
{
	if (a->capacity <= 3)
		sort_3(a);
	else if (a->capacity <= 5)
		sort_5(a, b);
	else
		sort_other(a, b);
}
int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	
	if (ac < 2)
		return (EXIT_FAILURE);
	a = init_a(ac, av);
	b = init_b(a.size);
	sort(&a, &b);
	free_all(&a, &b);
}
