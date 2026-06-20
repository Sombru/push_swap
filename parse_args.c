#include "push_swap.h"
#include "stack.h"

static int	count_tokens(char **argv)
{
	int	count;
	int	i;
	int	j;
	int	arg_tokens;

	count = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		arg_tokens = 0;
		while (argv[i][j])
		{
			while (ft_isspace(argv[i][j]))
				j++;
			if (argv[i][j])
			{
				count++;
				arg_tokens++;
			}
			while (argv[i][j] && !ft_isspace(argv[i][j]))
				j++;
		}
		if (arg_tokens == 0)
			return (-1);
		i++;
	}
	return (count);
}

static bool	parse_number(char *str, int *i, int *out)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (!ft_isdigit(str[*i]))
		return (false);
	while (str[*i] && !ft_isspace(str[*i]))
	{
		if (!ft_isdigit(str[*i]))
			return (false);
		value = value * 10 + (str[*i] - '0');
		if ((sign == 1 && value > INT_MAX)
			|| (sign == -1 && -value < INT_MIN))
			return (false);
		(*i)++;
	}
	*out = (int)(value * sign);
	return (true);
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

static int	*parse_all_args(char **argv, int *out_data_len)
{
	int	*data;
	int	i;
	int	j;
	int	k;
	int	value;

	*out_data_len = count_tokens(argv);
	if (*out_data_len <= 0)
		return (NULL);
	data = malloc(sizeof(int) * *out_data_len);
	if (!data)
		return (NULL);
	i = 1;
	k = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			while (ft_isspace(argv[i][j]))
				j++;
			if (argv[i][j] && (!parse_number(argv[i], &j, &value)
				|| has_duplicate(data, k, value)))
				return (free(data), NULL);
			if (argv[i][j] || (j > 0 && argv[i][j - 1]
				&& !ft_isspace(argv[i][j - 1])))
				data[k++] = value;
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
