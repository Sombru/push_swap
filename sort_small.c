/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:03:36 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	if (stack_is_sorted(a))
		return ;
	if (a->data[0] > a->data[1] && a->data[1] < a->data[2]
		&& a->data[0] < a->data[2])
		op_sa(a);
	else if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		op_sa(a);
		op_rra(a);
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
		op_ra(a);
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2]
		&& a->data[0] < a->data[2])
	{
		op_sa(a);
		op_ra(a);
	}
	else
		op_rra(a);
}

static int	min_pos(t_stack *a)
{
	size_t	i;
	size_t	best;

	i = 1;
	best = 0;
	while (i < a->size)
	{
		if (a->data[i] < a->data[best])
			best = i;
		i++;
	}
	return ((int)best);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	pos = min_pos(a);
	if ((size_t)pos <= a->size / 2)
	{
		while (pos-- > 0)
			op_ra(a);
	}
	else
	{
		pos = (int)a->size - pos;
		while (pos-- > 0)
			op_rra(a);
	}
	op_pb(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->data[0] > a->data[1])
	{
		op_sa(a);
		return ;
	}
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size)
		op_pa(a, b);
}
