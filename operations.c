#include "stack.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none
void	sa(t_stack *a)
{
	int	tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = tmp;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void	sb(t_stack *b)
{
	int	tmp;

	if (!b || b->size < 2)
		return ;
	tmp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = tmp;
}

// ss : sa and sb at the same time.
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty
void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (!a || !b || !b->size || a->capacity <= a->size)
		return ;
	value = stack_pop(b);
	stack_push(a, value);
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (!a || !b || !a->size || b->capacity <= b->size)
		return ;
	value = stack_pop(a);
	stack_push(b, value);
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
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

// b (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
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

// rr : ra and rb at the same time
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
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

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
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

// rrr : rra and rrb at the same time.
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
