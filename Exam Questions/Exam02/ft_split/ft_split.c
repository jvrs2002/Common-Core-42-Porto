#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	**ft_split(char *str);
size_t	ft_string_count(char *str);
size_t	ft_until_next(char *str);

char	**ft_split(char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	count;
	size_t	next;
	char	**array_str;

	i = 0;
	j = 0;
	count = ft_string_count(str);
	array_str = malloc(sizeof(char *) * (count + 1));
	while (j < count)
	{
		k = 0;
		i = 0;
		while (*str == ' ' || *str <= 13)
			str++;
		next = ft_until_next(str);
		array_str[j] = malloc(sizeof(char *) * (next + 1));
		while(i < next)
		{
			array_str[j][k] = str[i];
			i++;
			k++;
		}
		array_str[j][k] = '\0';
		j++;
		str += (next + 1);
	}
	array_str[j] = NULL;
	return (array_str);
}

size_t	ft_until_next(char *str)
{
	size_t	i;

	i = 0;
	while(str[i] != ' ' && str[i] > 13)
		i++;
	return (i);
}

size_t	ft_string_count(char *str)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] > 13)
		{
			++n;
			while(str[i] != '\0' && str[i] > 13 && str[i] != ' ')
				++i;
		}
		else
			++i;
	}
	return (n);
}

/* int	main()
{
	char	**array;

	array = ft_split("  starting and ending   ");

	printf("%s", array[2]);
} */
