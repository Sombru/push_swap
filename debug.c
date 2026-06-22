/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:04:26 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:05:11 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	size_t	i;

	ft_printf("====stack====\n");
	ft_printf("size: %zu, capacity: %zu\n", stack->size, stack->capacity);
	i = 0;
	while (i < stack->size)
	{
		ft_printf("data[%zu]: %d\n", i, stack->data[i]);
		i++;
	}
}
