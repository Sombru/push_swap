/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:03:47 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_stack *a, t_stack *b)
{
	pa(a, b);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	pb(a, b);
	write(1, "pb\n", 3);
}

void	op_ra(t_stack *a)
{
	ra(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	rb(b);
	write(1, "rb\n", 3);
}

void	op_rra(t_stack *a)
{
	rra(a);
	write(1, "rra\n", 4);
}
