/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:43:30 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/11 14:52:59 by joao-vri         ###   ########.fr       */
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
	if (!array_count)
		return (write(1, "Error\n", 6));
	if (array_count == 0)
		return (-1);
	else if (array_count == 1)
		nbrs = ft_parsing_one_argument(av, array_count);
	else
		nbrs = ft_parsing_multiple_arguments(av, array_count);
	if (!nbrs)
		return (write(1, "Error\n", 6));
	ft_init_container(container.head_a, nbrs, array_count);
	ft_initial_push(container.head_a, container.head_b, container.size_a_checkpoint, int *nbrs);
	return (0);
}

