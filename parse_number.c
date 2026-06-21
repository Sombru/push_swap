#include "push_swap.h"
#include "stack.h"

static int	parse_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static bool	add_digit(long *value, int sign, char digit)
{
	*value = *value * 10 + (digit - '0');
	if (sign == 1 && *value > INT_MAX)
		return (false);
	if (sign == -1 && -*value < INT_MIN)
		return (false);
	return (true);
}

bool	parse_number(char *str, int *i, int *out)
{
	long	value;
	int		sign;

	value = 0;
	sign = parse_sign(str, i);
	if (!ft_isdigit(str[*i]))
		return (false);
	while (str[*i] && !ft_isspace(str[*i]))
	{
		if (!ft_isdigit(str[*i]))
			return (false);
		if (!add_digit(&value, sign, str[*i]))
			return (false);
		(*i)++;
	}
	*out = (int)(value * sign);
	return (true);
}
