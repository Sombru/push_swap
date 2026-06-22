/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:06:53 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:08:13 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_stack(t_stack *a, t_stack *b)
{
	size_t	total;

	if (!a || !b || !compress_stack(a))
		return (false);
	if (stack_is_sorted(a))
		return (true);
	if (a->size <= 5)
		sort_small(a, b);
	else
	{
		total = a->size;
		push_by_rank_window(a, b, total);
		push_back_max(a, b);
	}
	return (true);
}
