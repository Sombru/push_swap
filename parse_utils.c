/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:03:51 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"

static int	count_arg_tokens(char *arg)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (arg[j])
	{
		while (ft_isspace(arg[j]))
			j++;
		if (arg[j])
			count++;
		while (arg[j] && !ft_isspace(arg[j]))
			j++;
	}
	if (count == 0)
		return (-1);
	return (count);
}

int	count_tokens(char **argv)
{
	int	count;
	int	arg_count;
	int	i;

	count = 0;
	i = 1;
	while (argv[i])
	{
		arg_count = count_arg_tokens(argv[i]);
		if (arg_count < 0)
			return (-1);
		count += arg_count;
		i++;
	}
	return (count);
}

static bool	has_duplicate(int *data, int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (data[i] == value)
			return (true);
		i++;
	}
	return (false);
}

bool	parse_token(char *arg, int *j, int *data, int *k)
{
	int	value;

	if (!parse_number(arg, j, &value))
		return (false);
	if (has_duplicate(data, *k, value))
		return (false);
	data[*k] = value;
	(*k)++;
	return (true);
}
