#include "stack.h"

t_stack	*stack_new(size_t size, int *data)
{
	t_stack	*res;

	if (!data)
		return (NULL);
	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->data = data;
	res->capacity = size;
	res->size = size;
	return (res);
}

t_stack	*stack_new_capacity(size_t size, size_t capacity, int *data)
{
	t_stack	*res;

	if (!data || size > capacity)
		return (NULL);
	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->data = data;
	res->capacity = capacity;
	res->size = size;
	return (res);
}

bool	stack_is_sorted(t_stack *stack)
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
