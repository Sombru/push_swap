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
	int val;
	
	if (!stack->size)
		return INT_MIN;
	stack->size--;
	val = stack->data[stack->size];
	return val;
}

// peek a value on top of the stack
int stack_top(t_stack *stack)
{
	if (!stack->size)
		return INT_MIN;
	return stack->data[stack->size-1];
}

// push the value on top of the stack
bool stack_push(t_stack *stack, int value)
{
	if (stack->capacity <= stack->size)
		return false;
	stack->data[stack->size] = value;
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