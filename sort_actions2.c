#include "stack.h"

void	op_sa(t_stack *a)
{
	sa(a);
	write(1, "sa\n", 3);
}

void	op_rrb(t_stack *b)
{
	rrb(b);
	write(1, "rrb\n", 4);
}
