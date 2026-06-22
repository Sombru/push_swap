/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:03:29 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:16:52 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(size_t size, int *data)
{
	t_stack	*res;

	if (!data)
		return (NULL);
	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->data = data;
	res->capacity = size;
	res->size = size;
	return (res);
}

t_stack	*stack_new_capacity(size_t size, size_t capacity, int *data)
{
	t_stack	*res;

	if (!data || size > capacity)
		return (NULL);
	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->data = data;
	res->capacity = capacity;
	res->size = size;
	return (res);
}
