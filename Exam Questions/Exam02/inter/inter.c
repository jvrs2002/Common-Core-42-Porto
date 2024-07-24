#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*inter(char *str_big, char *str_small);
int	ft_check_double(char *new_str, char str_small);
size_t	ft_strlen(char *str);

char	*inter(char *str_small, char *str_big)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new_str;

	new_str = malloc(sizeof(char) * (ft_strlen(str_small) + 1));
	i = 0;
	j = 0;
	k = 0;
	while(str_small[j])
	{
		if (str_small[j] == str_big[i])
		{
			if (ft_check_double(new_str, str_small[j]) == 1)
			{
				new_str[k] = str_small[j];
				k++;
				j++;
				i = 0;
			}
			else
			{
				j++;
				i = 0;
			}
		}
		i++;
		if (str_big[i] == '\0')
		{
			j++;
			i = 0;
		}
	}
	return(new_str);
}

int	ft_check_double(char *new_str, char str_small)
{
	size_t	i;

	i = 0;
	while(new_str[i])
	{
		if (new_str[i] == str_small)
			return (-1);
		else
			i++;
	}
	return (1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	char	*str;
	size_t	i;

	i = 0;
	if (ac == 3)
	{
		str = inter(av[1], av[2]);
		while(str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
