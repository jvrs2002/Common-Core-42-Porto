/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:43:30 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/09 13:17:41 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	int	*nbrs;
	size_t	array_count;
	t_container	container;
	char	*input;

	nbrs = NULL;
	array_count = ft_input_count(ac, av[1], " ");
	if (array_count == 0)
		return (-1);
	else if (array_count == 1)
		nbrs = ft_parsing_one_argument(av, array_count);
	else
		nbrs = ft_parsing_multiple_arguments(av, array_count);
	ft_push_to_container(container.head_a, nbrs, array_count);
	return (0);
}

