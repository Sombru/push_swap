#include "stack.h"
#include "libft.h"

static char	*append_char(char *line, size_t len, char c)
{
	char	*new_line;
	size_t	i;

	new_line = malloc(sizeof(char) * (len + 2));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[len] = c;
	new_line[len + 1] = '\0';
	free(line);
	return (new_line);
}

static bool	read_failed(char *line, ssize_t bytes, int *status)
{
	if (bytes >= 0)
		return (false);
	free(line);
	*status = -1;
	return (true);
}

static char	*read_alloc_failed(int *status)
{
	*status = -1;
	return (NULL);
}

char	*read_instruction(int *status)
{
	char	buffer;
	char	*line;
	ssize_t	bytes;
	size_t	len;

	line = NULL;
	len = 0;
	*status = 1;
	bytes = read(0, &buffer, 1);
	while (bytes > 0)
	{
		line = append_char(line, len++, buffer);
		if (!line)
			return (read_alloc_failed(status));
		if (buffer == '\n')
			return (line);
		bytes = read(0, &buffer, 1);
	}
	if (read_failed(line, bytes, status))
		return (NULL);
	*status = 0;
	return (line);
}
