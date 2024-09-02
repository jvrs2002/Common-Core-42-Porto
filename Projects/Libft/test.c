#include "libft.h"

int	*ft_convert_input(int ac, char **av);
void	ft_free_array(int i, char **strs);

void	ft_free_array(int i, char **strs)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
}

int	main(int ac, char **av)
{
	int	*nbrs;
	size_t	i;

	i = 0;
	nbrs = ft_convert_input(ac, av);
	while(nbrs[i])
	{
		printf("%i ", nbrs[i]);
		++i;
	}
	free(nbrs);
	return (0);
}

int	*ft_convert_input(int ac, char **av)
{
	char **input;
	int	*nbrs;
	int	i;
	int	array_count;

	array_count = 0;
	nbrs = NULL;
	input = NULL;
	i = 0;
	if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		while (input[i])
			++i;
		array_count = i;
		nbrs = (int *)malloc(sizeof(int) * array_count);
		if (!nbrs)
			return (NULL);
		while (input[--i] && i >= 0)
			nbrs[i] = ft_atoi(input[i]);
		ft_free_array(array_count, input);
	}
	else
	{
		nbrs = (int *)malloc(sizeof(int) * (ac - 1));
		if (!nbrs)
			return (NULL);
		while (av[i + 1])
		{
			nbrs[i] = ft_atoi(av[i + 1]);
			++i;
		}
	}
	return (nbrs);
}
