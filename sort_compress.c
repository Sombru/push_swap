/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_compress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:03:43 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_ints(int *arr, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 1;
	while (i < size)
	{
		tmp = arr[i];
		j = i;
		while (j > 0 && arr[j - 1] > tmp)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = tmp;
		i++;
	}
}

static int	find_rank(int *sorted, size_t size, int value)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return ((int)i);
		i++;
	}
	return (-1);
}

static bool	has_sorted_duplicate(int *sorted, size_t size)
{
	size_t	i;

	i = 1;
	while (i < size)
	{
		if (sorted[i - 1] == sorted[i])
			return (true);
		i++;
	}
	return (false);
}

static void	fill_sorted(int *sorted, t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		sorted[i] = a->data[i];
		i++;
	}
	sort_ints(sorted, a->size);
}

bool	compress_stack(t_stack *a)
{
	int		*sorted;
	size_t	i;

	sorted = malloc(sizeof(int) * a->size);
	if (!sorted)
		return (false);
	fill_sorted(sorted, a);
	if (has_sorted_duplicate(sorted, a->size))
	{
		free(sorted);
		return (false);
	}
	i = 0;
	while (i < a->size)
	{
		a->data[i] = find_rank(sorted, a->size, a->data[i]);
		i++;
	}
	free(sorted);
	return (true);
}
