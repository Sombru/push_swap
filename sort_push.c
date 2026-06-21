#include "stack.h"

int	decision_range(size_t size)
{
	if (size <= 100)
		return (15);
	return (33);
}

void	push_by_rank_window(t_stack *a, t_stack *b, size_t total)
{
	int	count;
	int	range;

	count = 0;
	range = decision_range(total);
	while (a->size)
	{
		if (stack_top(a) <= count)
		{
			op_pb(a, b);
			if (b->size > 1)
				op_rb(b);
			count++;
		}
		else if (stack_top(a) <= count + range)
		{
			op_pb(a, b);
			count++;
		}
		else
			op_ra(a);
	}
}

static int	max_pos(t_stack *b)
{
	size_t	i;
	size_t	best;

	i = 1;
	best = 0;
	while (i < b->size)
	{
		if (b->data[i] > b->data[best])
			best = i;
		i++;
	}
	return ((int)best);
}

static void	rotate_b_to_pos(t_stack *b, int pos)
{
	if ((size_t)pos <= b->size / 2)
	{
		while (pos-- > 0)
			op_rb(b);
	}
	else
	{
		pos = (int)b->size - pos;
		while (pos-- > 0)
			op_rrb(b);
	}
}

void	push_back_max(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		rotate_b_to_pos(b, max_pos(b));
		op_pa(a, b);
	}
}
