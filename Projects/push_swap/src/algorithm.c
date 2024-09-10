/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:12:20 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/10 15:05:53 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_to_container(t_data **head_a, int *nbrs, size_t array_count)
{
	while (array_count != 0)
	{
		ft_push(head_a, nbrs[array_count]);
		--array_count;
	}
}



int	*ft_bubble_sort(int *nbrs, size_t size_checkpoint)
{
	int	*nbrs_sorted;
	nbrs_sorted = malloc(sizeof(int) * size_checkpoint);
}

int	ft_calc_median (int *nbrs, size_t container_size)
{
	int	i;
	int	median;

	if (container_size == 0)
		return (0);
	i = container_size / 2;
	if (container_size % 2 == 0)
	{
		median = nbrs[i - 1] + nbrs[i];
		if (median % 2 != 0)
			++median;
		median /= 2;
	}
	else if (container_size % 2 != 0)
		median = nbrs[i];
	return (median);
}
