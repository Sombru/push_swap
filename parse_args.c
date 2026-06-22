/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkostura <pkostura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:04:05 by pkostura          #+#    #+#             */
/*   Updated: 2026/06/22 13:04:55 by pkostura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"

static int	*alloc_data(char **argv, int *out_data_len)
{
	*out_data_len = count_tokens(argv);
	if (*out_data_len <= 0)
		return (NULL);
	return (malloc(sizeof(int) * *out_data_len));
}

static bool	parse_arg_tokens(char *arg, int *data, int *k)
{
	int	j;

	j = 0;
	while (arg[j])
	{
		while (ft_isspace(arg[j]))
			j++;
		if (arg[j] && !parse_token(arg, &j, data, k))
			return (false);
	}
	return (true);
}

static int	*parse_all_args(char **argv, int *out_data_len)
{
	int	*data;
	int	i;
	int	k;

	data = alloc_data(argv, out_data_len);
	if (!data)
		return (NULL);
	i = 1;
	k = 0;
	while (argv[i])
	{
		if (!parse_arg_tokens(argv[i], data, &k))
		{
			free(data);
			return (NULL);
		}
		i++;
	}
	return (data);
}

int	*parse_args_mul(char **argv, int *out_data_len)
{
	return (parse_all_args(argv, out_data_len));
}

int	*parse_args(char **argv, int *out_data_len)
{
	return (parse_all_args(argv, out_data_len));
}
