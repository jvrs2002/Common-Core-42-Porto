/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:43:30 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/17 17:29:03 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	int	*nbrs;
	size_t	array_count;
	char	*input;
	t_container container;
	size_t	i = 0;

	container.head_a = NULL;
	container.head_b = NULL;
	container.size_b_checkpoint = 0;
	nbrs = NULL;
	if (array_count <= 0)
	{
		write(1, "Error ARRAY_COUNT 0\n", 21);
		return (EXIT_FAILURE);
	}
	if (ac == 2)
		nbrs = ft_parsing_one_argument(av, &array_count);
	else if (ac > 2)
		nbrs = ft_parsing_multiple_arguments(av, &array_count);
		container.size_a_checkpoint = array_count;
	if (!nbrs)
	{
		write(1, "Error NBRS\n", 11);
		return EXIT_FAILURE;
	}
	ft_init_container(&container.head_a, nbrs, array_count);
	//ft_initial_push(&container.head_a, &container.head_b, &container.size_a_checkpoint, nbrs);
	ft_print_list(&container.head_a);
	free(nbrs);
	return (0);
}

