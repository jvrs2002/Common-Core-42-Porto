#include <unistd.h>

void	camel_to_snake(char *str)
{
	size_t	i;
	char	temp;
	
	temp = '\0';
	i = 0;
	if (str[0] >= 'A' && str[0] <= 'Z')
		return ;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			write(1, "_", 1);
			temp = str[i];
			temp += 32;
			write(1, &temp, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write (1, "\n", 1);
		return (-1);
	}
	camel_to_snake(av[1]);
}
