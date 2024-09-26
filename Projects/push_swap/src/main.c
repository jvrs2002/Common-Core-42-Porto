/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:43:30 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/26 13:57:12 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	int	*nbrs;
	size_t	array_count;
	char	*input;
	t_container container;

	container.head_a = NULL;
	container.head_b = NULL;
	container.size_b_checkpoint = 0;
	array_count = ac - 1;
	if (array_count == 1)
		nbrs = ft_parse_one_argument(av, &array_count);
	else if (array_count > 1)
		nbrs = ft_parse_multiple_arguments(av, array_count);
	container.size_a_checkpoint = array_count;
	if (array_count == 0 || !nbrs)
		return(write(1, "Error\n", 7));
	ft_init_container(&container.head_a, nbrs, array_count);
	while(container.size_a_checkpoint > 3)
	{
		ft_median_pb(&container.head_a, &container.head_b, &container, nbrs);
		nbrs = ft_copy_to_array(ft_bubble_sort(nbrs, container.size_a_checkpoint), container.head_a, &container.size_a_checkpoint);
	}
	ft_first_sort_a(&container.head_a, &container.size_a_checkpoint);
	while (container.size_b_checkpoint > 2)
	{
		nbrs = ft_copy_to_array(ft_bubble_sort(nbrs, container.size_b_checkpoint), container.head_b, &container.size_b_checkpoint);
		ft_median_pa(&container.head_a, &container.head_b, &container, nbrs);
	}
	printf("size of a: %zu\n", container.size_a_checkpoint);
	ft_print_list(&container.head_a);
	write(1, "\n\n", 2);
	printf("size of b: %zu\n", container.size_b_checkpoint);
	ft_print_list(&container.head_b);
	free(nbrs);
}

