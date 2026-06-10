#include "stack.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = tmp;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b || b->size < 2)
		return ;
	tmp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (!a || !b || !b->size || a->capacity <= a->size)
		return ;
	value = stack_pop(b);
	stack_push(a, value);
}

void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (!a || !b || !a->size || b->capacity <= b->size)
		return ;
	value = stack_pop(a);
	stack_push(b, value);
}

void	ra(t_stack *a)
{
	size_t	i;
	int		first;

	if (!a || a->size < 2)
		return ;
	first = a->data[0];
	i = 0;
	while (i + 1 < a->size)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = first;
}

void	rb(t_stack *b)
{
	size_t	i;
	int		first;

	if (!b || b->size < 2)
		return ;
	first = b->data[0];
	i = 0;
	while (i + 1 < b->size)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->size - 1] = first;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	size_t	i;
	int		last;

	if (!a || a->size < 2)
		return ;
	last = a->data[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = last;
}

void	rrb(t_stack *b)
{
	size_t	i;
	int		last;

	if (!b || b->size < 2)
		return ;
	last = b->data[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
