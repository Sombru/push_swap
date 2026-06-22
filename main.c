/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:04:28 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:06:25 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		*data;
	int		data_len;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		data = parse_args(argv, &data_len);
	else
		data = parse_args_mul(argv, &data_len);
	if (!init_stacks(&a, &b, data, data_len))
		return (print_error());
	if (!sort_stack(a, b))
	{
		stack_delete(a);
		stack_delete(b);
		return (print_error());
	}
	stack_delete(a);
	stack_delete(b);
	return (0);
}
