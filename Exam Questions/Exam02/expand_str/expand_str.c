#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

size_t	ft_until_next(char *str);
size_t	ft_count_words(char *str);
size_t	ft_strlen(char *str);
char	*expand_str(char *str);

char	*expand_str(char *str)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	next;
	size_t	three;
	char	*new_str;

	j = 0;
	count = ft_count_words(str);
	new_str = malloc((sizeof(char)) * (ft_strlen(str) + ((count - 1) * 3)));
	i = 0;
	while (str[j] != '\0')
	{
		while (str[j] == ' ' || str[j] <= 13)
			j++;
		next = ft_until_next(&str[j]) + i;
		while (i < next)
		{
			new_str[i] = str[j];
			j++;
			i++;
		}
		while (str[j] == ' ' || str[j] <= 13 && str[j])
			j++;
		if (str[j] != '\0')
		{
			three = i + 3;
			while (i < three)
			{
				new_str[i] = ' ';
				i++;
			}
		}
	}
	return (new_str);
}

size_t	ft_until_next(char *str)
{
	size_t	i;

	i = 0;

	while(str[i] != ' ' && str[i] > 13)
		i++;
	return (i);
}

size_t	ft_count_words(char *str)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > 13 && str[i] != ' ')
		{
			j++;
			while (str[i] != ' ' && str[i] > 13)
				i++;
		}
		else
			i++;
	}
	return (j);
}
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*str;
	size_t	i;

	i = 0;
	if (argc == 2 && argv[1][0] != '\0')
	{
		str = expand_str(argv[1]);
		while (str[i] != 0)
		{
			write (1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
