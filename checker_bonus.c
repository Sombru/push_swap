/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:04:35 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:56 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

	line = read_instruction(&status);
	while (line)
	{
		if (!apply_instruction(line, a, b))
			return (error_exit(a, b, line));
		free(line);
		line = read_instruction(&status);
	}
	if (status == -1)
		return (error_exit(a, b, NULL));
	if (b->size == 0 && stack_is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(a, b);
	return (0);
}

static bool	init_stacks(t_stack **a, t_stack **b, int *a_data, int data_len)
{
	int	*b_data;

	*a = stack_new(data_len, a_data);
	b_data = malloc(sizeof(int) * data_len);
	if (!*a || !b_data)
	{
		stack_delete(*a);
		free(b_data);
		return (false);
	}
	*b = stack_new_capacity(0, data_len, b_data);
	if (!*b)
	{
		stack_delete(*a);
		free(b_data);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*a_data;
	int		data_len;

	if (argc < 2)
		return (0);
	if (argc == 2)
		a_data = parse_args(argv, &data_len);
	else
		a_data = parse_args_mul(argv, &data_len);
	if (!a_data)
		return (print_error());
	if (!init_stacks(&a, &b, a_data, data_len))
	{
		free(a_data);
		return (print_error());
	}
	return (run_checker(a, b));
}
