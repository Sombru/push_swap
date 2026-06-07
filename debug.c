#include "stack.h"
#include "push_swap.h"

void print_stack(t_stack *stack)
{
	ft_printf("====stack====\n");
	ft_printf("size: %zu, capacity: %zu\n", stack->size, stack->capacity);
	for (size_t i = 0; i < stack->size; ++i)
		ft_printf("data[%zu]: %d\n", i, stack->data[i]);
}