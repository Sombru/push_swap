#include "push_swap.h"
#include "stack.h"


int main(int argc, char **argv)
{
	int *data;
	int data_len;
	t_stack *stack;

	if (argc < 2)
		return (0);
	if (argc == 2)
		data = parse_args(argv, &data_len);
	else
		data = parse_args_mul(argv, &data_len);
	
	stack = stack_new(data_len, data);
	if (!stack)
		return (write(2, "error\n", 6));
	stack_pop(stack);
	stack_push(stack, 6);
	
	// ft_printf("%d\n", stack_top(stack));
	
	print_stack(stack);
	
	stack_delete(stack);
	
	return (0);
	
}
