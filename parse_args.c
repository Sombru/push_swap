#include "push_swap.h"

// use this parser if input is in multiple arg (./push_swap "12 3)
int *parse_args_mul(char **argv, int *out_data_len)
{
	int	i;
	int	j;
	int	*data;

	i = 1;
	while (argv[i])
		i++;
	data = malloc(sizeof(int) * (i - 1));
	if (!data)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
		{
			free(data);
			return (NULL);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				free(data);
				return (NULL);
			}
			j++;
		}
		data[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	*out_data_len = i - 1;
	return (data);
}


// use this parser if input is in one arg (./push_swap "1 2 3")
int *parse_args(char **argv, int *out_data_len)
{
	int i;
	int k;
	int *data;

	i = 0;
	k = 0;

	data = malloc(sizeof(int) *ft_strlen(argv[1]));
	if (!data)
		return NULL;
	while ((argv[1][i]))
	{
		while (ft_isspace(argv[1][i]))
		{
			++i;
			continue;
		}
		if (ft_isdigit(argv[1][i]))
			data[k++] = ft_atoi(&argv[1][i]);
		while (ft_isdigit(argv[1][i]))
		{
			if (ft_isalpha(argv[1][i]))
			{
				free(data);
				return (NULL);
			}
			++i;
		}
	}
	*out_data_len = k;
	return data;	
}
