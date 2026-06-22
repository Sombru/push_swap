/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:04:11 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	size_t	i;
	int		first;

	if (!a || a->size < 2)
		return ;
	first = a->data[0];
	i = 0;
	while (i + 1 < a->size)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = first;
}

void	rb(t_stack *b)
{
	size_t	i;
	int		first;

	if (!b || b->size < 2)
		return ;
	first = b->data[0];
	i = 0;
	while (i + 1 < b->size)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->size - 1] = first;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
