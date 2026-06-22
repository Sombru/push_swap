/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:03:38 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_pop(t_stack *stack)
{
	size_t	i;
	int		val;

	if (!stack || !stack->size)
		return (INT_MIN);
	val = stack->data[0];
	i = 0;
	while (i + 1 < stack->size)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->size--;
	return (val);
}

int	stack_top(t_stack *stack)
{
	if (!stack || !stack->size)
		return (INT_MIN);
	return (stack->data[0]);
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

bool	stack_push(t_stack *stack, int value)
{
	size_t	i;

	if (!stack || stack->capacity <= stack->size)
		return (false);
	i = stack->size;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = value;
	stack->size++;
	return (true);
}

void	stack_delete(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->data)
		free(stack->data);
	free(stack);
}
