#include "stack.h"

static bool	is_sorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (false);
		i++;
	}
	return (true);
}

static void	op_sa(t_stack *a)
{
	sa(a);
	write(1, "sa\n", 3);
}

static void	op_pa(t_stack *a, t_stack *b)
{
	pa(a, b);
	write(1, "pa\n", 3);
}

static void	op_pb(t_stack *a, t_stack *b)
{
	pb(a, b);
	write(1, "pb\n", 3);
}

static void	op_ra(t_stack *a)
{
	ra(a);
	write(1, "ra\n", 3);
}

static void	op_rb(t_stack *b)
{
	rb(b);
	write(1, "rb\n", 3);
}

static void	op_rra(t_stack *a)
{
	rra(a);
	write(1, "rra\n", 4);
}

static void	op_rrb(t_stack *b)
{
	rrb(b);
	write(1, "rrb\n", 4);
}

static void	sort_ints(int *arr, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 1;
	while (i < size)
	{
		tmp = arr[i];
		j = i;
		while (j > 0 && arr[j - 1] > tmp)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = tmp;
		i++;
	}
}

static int	find_rank(int *sorted, size_t size, int value)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return ((int)i);
		i++;
	}
	return (-1);
}


// Rank compression replaces the original values with their sorted positions
static bool	compress_stack(t_stack *a)
{
	int		*sorted;
	size_t	i;

	sorted = malloc(sizeof(int) * a->size);
	if (!sorted)
		return (false);
	i = 0;
	while (i < a->size)
	{
		sorted[i] = a->data[i];
		i++;
	}
	sort_ints(sorted, a->size);
	i = 1;
	while (i < a->size)
	{
		if (sorted[i - 1] == sorted[i])
		{
			free(sorted);
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		a->data[i] = find_rank(sorted, a->size, a->data[i]);
		i++;
	}
	free(sorted);
	return (true);
}

static int	decision_range(size_t size)
{
	if (size <= 100)
		return (15);
	return (33);
}

static void	push_by_rank_window(t_stack *a, t_stack *b, size_t total)
{
	int	count;
	int	range;

	count = 0;
	range = decision_range(total);
	while (a->size)
	{
		if (a->data[0] <= count)
		{
			op_pb(a, b);
			if (b->size > 1)
				op_rb(b);
			count++;
		}
		else if (a->data[0] <= count + range)
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

static void	push_back_max(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->size)
	{
		pos = max_pos(b);
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
		op_pa(a, b);
	}
}

static void	sort_three(t_stack *a)
{
	if (is_sorted(a))
		return ;
	if (a->data[0] > a->data[1] && a->data[1] < a->data[2]
		&& a->data[0] < a->data[2])
		op_sa(a);
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		op_sa(a);
		op_rra(a);
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
		op_ra(a);
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] < a->data[2])
	{
		op_sa(a);
		op_ra(a);
	}
	else
		op_rra(a);
}

static int	min_pos(t_stack *a)
{
	size_t	i;
	size_t	best;

	i = 1;
	best = 0;
	while (i < a->size)
	{
		if (a->data[i] < a->data[best])
			best = i;
		i++;
	}
	return ((int)best);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	pos = min_pos(a);
	if ((size_t)pos <= a->size / 2)
	{
		while (pos-- > 0)
			op_ra(a);
	}
	else
	{
		pos = (int)a->size - pos;
		while (pos-- > 0)
			op_rra(a);
	}
	op_pb(a, b);
}

static void	sort_small(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size)
		op_pa(a, b);
}

// rank-compression + chunk/window sorting algorithm
bool	sort_stack(t_stack *a)
{
	t_stack	*b;
	int		*b_data;
	size_t	total;

	if (!a || !compress_stack(a))
		return (false);
	if (is_sorted(a))
		return (true);
	b_data = malloc(sizeof(int) * a->capacity);
	if (!b_data)
		return (false);
	b = stack_new_capacity(0, a->capacity, b_data);
	if (!b)
		return (free(b_data), false);
	if (a->size <= 5)
		sort_small(a, b);
	else
	{
		total = a->size;
		push_by_rank_window(a, b, total);
		push_back_max(a, b);
	}
	stack_delete(b);
	return (true);
}
