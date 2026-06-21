#include "stack.h"

static t_stack	*create_b_stack(size_t capacity)
{
	t_stack	*b;
	int		*b_data;

	b_data = malloc(sizeof(int) * capacity);
	if (!b_data)
		return (NULL);
	b = stack_new_capacity(0, capacity, b_data);
	if (!b)
	{
		free(b_data);
		return (NULL);
	}
	return (b);
}

bool	sort_stack(t_stack *a)
{
	t_stack	*b;
	size_t	total;

	if (!a || !compress_stack(a))
		return (false);
	if (stack_is_sorted(a))
		return (true);
	b = create_b_stack(a->capacity);
	if (!b)
		return (false);
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
