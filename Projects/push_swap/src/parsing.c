/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:30:37 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/09 16:54:24 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_parsing_multiple_arguments(char **av, size_t array_count)
{
	char **input;
	int	*nbrs;
	int	i;

	input = NULL;
	i = 0;
	nbrs = (int *)malloc(sizeof(int) * (array_count));
	if (!nbrs)
		return (NULL);
	while (i < array_count)
	{
		nbrs[i] = ft_atol(av[i + 1]);
		++i;
	}
	return (nbrs);
}

int	*ft_parsing_one_argument(char **av, size_t array_count)
{
	char **input;
	int	*nbrs;
	int	i;

	input = NULL;
	nbrs = NULL;
	i = 0;
	input = ft_split(av[1], ' ');
	if (!input)
		return (NULL);
	nbrs = (int *)malloc(sizeof(int) * (array_count));
	if (!nbrs)
	{
		ft_free_array(array_count, input);
		return (NULL);
	}
	while (i < array_count)
	{
		nbrs[i] = ft_atol(input[i]);
		++i;
	}
	ft_free_array(array_count, input);
	return (nbrs);
}

size_t	ft_input_count(int ac, char *str, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
		return (n + 1);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			++n;
			while (str[i] != '\0' && str[i] != c)
			{
				if (str[i] != c && (str[i] < '0' || str[i] > '9'))
					break ;
				++i;
			}
		}
		else
			++i;
	}
	return (n);
}

/* int main(int ac, char **av)
{
	char **input;
	int *nbrs;
	int i;
	int array_count;

	input = NULL;
	if (ac == 1)
	{
		nbrs = NULL;
		return (0);
	}
	if (ac == 2)
	{
		nbrs = ft_parsing_one_argument(av);
		input = ft_split(av[1], ' ');
		array_count = 0;
		while (input[array_count])
			++array_count;
		ft_free_array(array_count, input);
	}
	else if (ac > 2)
	{
		nbrs = ft_parsing_multiple_arguments(ac, av);
		array_count = ac - 1;
	}
	else
		array_count = 0;
	for (i = 0; i < array_count; ++i)
		printf("%d ", nbrs[i]);
	printf("\n");
	free(nbrs);
	return (0);
} */
