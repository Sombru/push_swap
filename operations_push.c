/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:04:21 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (!a || !b || !b->size || a->capacity <= a->size)
		return ;
	value = stack_pop(b);
	stack_push(a, value);
}

void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (!a || !b || !a->size || b->capacity <= b->size)
		return ;
	value = stack_pop(a);
	stack_push(b, value);
}
