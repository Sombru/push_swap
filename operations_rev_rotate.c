/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:04:19 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	size_t	i;
	int		last;

	if (!a || a->size < 2)
		return ;
	last = a->data[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = last;
}

void	rrb(t_stack *b)
{
	size_t	i;
	int		last;

	if (!b || b->size < 2)
		return ;
	last = b->data[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = last;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
