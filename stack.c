#include "stack.h"

// create new stack on the heap with given size and data (data is expected to be allocated)
t_stack *stack_new(size_t size, int *data)
{
	t_stack *res;

	if (!data)
		return NULL;
	res = malloc(sizeof(t_stack));
	if (!res)
		return NULL;
	res->data = data;
	res->capacity = size;
	res->size = size;
	return res;
}

// delete a value on top of the stack and return it (or int min if stack is epmty)
int stack_pop(t_stack *stack)
{
	size_t	i;
	int val;
	
	if (!stack || !stack->size)
		return INT_MIN;
	val = stack->data[0];
	i = 0;
	while (i + 1 < stack->size)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->size--;
	return val;
}

// peek a value on top of the stack
int stack_top(t_stack *stack)
{
	if (!stack || !stack->size)
		return INT_MIN;
	return stack->data[0];
}

// push the value on top of the stack
bool stack_push(t_stack *stack, int value)
{
	size_t	i;

	if (!stack || stack->capacity <= stack->size)
		return false;
	i = stack->size;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = value;
	stack->size++;
	return true;
}

// free the stack and its data (including data)
void stack_delete(t_stack *stack)
{
	if (stack->data)
		free(stack->data);
	free(stack);
}
