#include "stack.h"
#include "libft.h"

static bool	same_instruction(char *line, char *instruction)
{
	size_t	i;

	i = 0;
	while (instruction[i] && line[i] == instruction[i])
		i++;
	if (instruction[i])
		return (false);
	return (line[i] == '\0' || (line[i] == '\n' && line[i + 1] == '\0'));
}

bool	apply_instruction(char *line, t_stack *a, t_stack *b)
{
	if (same_instruction(line, "sa"))
		sa(a);
	else if (same_instruction(line, "sb"))
		sb(b);
	else if (same_instruction(line, "ss"))
		ss(a, b);
	else if (same_instruction(line, "pa"))
		pa(a, b);
	else if (same_instruction(line, "pb"))
		pb(a, b);
	else if (same_instruction(line, "ra"))
		ra(a);
	else if (same_instruction(line, "rb"))
		rb(b);
	else if (apply_reverse_instruction(line, a, b))
		return (true);
	else
		return (false);
	return (true);
}

bool	apply_reverse_instruction(char *line, t_stack *a, t_stack *b)
{
	if (same_instruction(line, "rr"))
		rr(a, b);
	else if (same_instruction(line, "rra"))
		rra(a);
	else if (same_instruction(line, "rrb"))
		rrb(b);
	else if (same_instruction(line, "rrr"))
		rrr(a, b);
	else
		return (false);
	return (true);
}
