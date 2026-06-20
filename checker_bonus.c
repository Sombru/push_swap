#include "stack.h"
#include "libft.h"

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

static char	*append_char(char *line, size_t len, char c)
{
	char	*new_line;
	size_t	i;

	new_line = malloc(sizeof(char) * (len + 2));
	if (!new_line)
		return (free(line), NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[len] = c;
	new_line[len + 1] = '\0';
	free(line);
	return (new_line);
}

static char	*read_line(int *status)
{
	char	buffer;
	char	*line;
	ssize_t	bytes;
	size_t	len;

	line = NULL;
	len = 0;
	*status = 1;
	bytes = read(0, &buffer, 1);
	while (bytes > 0)
	{
		line = append_char(line, len++, buffer);
		if (!line)
			return (*status = -1, NULL);
		if (buffer == '\n')
			return (line);
		bytes = read(0, &buffer, 1);
	}
	if (bytes < 0)
		return (free(line), *status = -1, NULL);
	*status = 0;
	return (line);
}

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

static bool	apply_instruction(char *line, t_stack *a, t_stack *b)
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
	else if (same_instruction(line, "rr"))
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

static void	free_stacks(t_stack *a, t_stack *b)
{
	stack_delete(a);
	stack_delete(b);
}

static int	error_exit(t_stack *a, t_stack *b, char *line)
{
	free(line);
	free_stacks(a, b);
	write(2, "Error\n", 6);
	return (1);
}

static int	run_checker(t_stack *a, t_stack *b)
{
	char	*line;
	int		status;

	line = read_line(&status);
	while (line)
	{
		if (!apply_instruction(line, a, b))
			return (error_exit(a, b, line));
		free(line);
		line = read_line(&status);
	}
	if (status == -1)
		return (error_exit(a, b, NULL));
	if (b->size == 0 && is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(a, b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_data;
	int		*b_data;
	int		data_len;

	if (argc < 2)
		return (0);
	if (argc == 2)
		a_data = parse_args(argv, &data_len);
	else
		a_data = parse_args_mul(argv, &data_len);
	if (!a_data)
		return (write(2, "Error\n", 6), 1);
	a = stack_new(data_len, a_data);
	b_data = malloc(sizeof(int) * data_len);
	if (!a || !b_data)
	{
		if (a)
			stack_delete(a);
		else
			free(a_data);
		free(b_data);
		return (write(2, "Error\n", 6), 1);
	}
	b = stack_new_capacity(0, data_len, b_data);
	if (!b)
		return (stack_delete(a), free(b_data), write(2, "Error\n", 6), 1);
	return (run_checker(a, b));
}
