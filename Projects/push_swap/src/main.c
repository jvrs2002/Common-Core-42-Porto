/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:30:37 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/02 14:45:22 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_convert_input(int ac, char **av);

int	*ft_convert_input(int ac, char **av)
{
	char **input;
	int	*nbrs;
	int	i;
	int	array_count;

	array_count = 0;
	input = NULL;
	i = 0;
	if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		while (input[i])
			++i;
		array_count = i;
		nbrs = (int *)malloc(sizeof(int) * i);
		if (!nbrs)
			return (NULL);
		while (input[--i] && i > -1)
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
