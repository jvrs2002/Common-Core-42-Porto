/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:30:37 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/19 13:30:53 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_parse_multiple_arguments(char **av, size_t array_count)
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
		nbrs[i] = ft_atoi(av[i + 1]);
		if (!nbrs[i] && *av[i + 1] != '0')
		{
			free(nbrs);
			return (NULL);
		}
		++i;
	}
	return (nbrs);
}

int	*ft_parse_one_argument(char **av, size_t *array_count)
{
	char **input;
	int	*nbrs;
	int	i;

	*array_count = ft_input_count(av[1], ' ');
	input = NULL;
	nbrs = NULL;
	i = -1;
	input = ft_split(av[1], ' ');
	if (!input)
		return (NULL);
	nbrs = (int *)malloc(sizeof(int) * (*array_count));
	if (!nbrs)
		return (ft_free_array(*array_count, input));
	while (++i < *array_count)
	{
		nbrs[i] = ft_atoi(input[i]);
		if (!nbrs[i] && *input[i] != '0')
		{
			free(nbrs);
			return (ft_free_array(*array_count, input));
		}
	}
	ft_free_array(*array_count, input);
	return (nbrs);
}

size_t	ft_input_count(const char *str, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			++n;
			while (str[i] != '\0' && str[i] != c)
			{
				if (str[i] != c && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
					break ;
				++i;
			}
		}
		else
			++i;
	}
	return (n);
}

