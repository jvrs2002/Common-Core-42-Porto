/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:12:20 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/11 14:50:47 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_init_container(t_data **head_a, int *nbrs, size_t array_count)
{
	while (array_count != 0)
	{
		ft_push(head_a, nbrs[array_count]);
		--array_count;
	}
}

int	*ft_bubble_sort(int *nbrs, size_t size_checkpoint)
{
	size_t	i;
	int	swap;
	int	*nbrs_sorted;

	nbrs_sorted = (int *)malloc(sizeof(int) * size_checkpoint);
	if (!nbrs_sorted)
		return (NULL);
	ft_memcpy(nbrs_sorted, nbrs, size_checkpoint * sizeof(int));
	while (size_checkpoint != 0)
	{
		i = 0;
		while (i < size_checkpoint - 1)
		{
			if (nbrs_sorted[i] > nbrs_sorted[i + 1])
			{
				swap = nbrs_sorted[i];
				nbrs_sorted[i] = nbrs_sorted[i + 1];
				nbrs_sorted[i + 1] = swap;
			}
			++i;
		}
		--size_checkpoint;
	}
	return (nbrs_sorted);
}

int	ft_calc_median (int *nbrs_sorted, size_t container_size)
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

void	ft_initial_push(t_data **head_a, t_data **head_b, size_t size_checkpoint_a, int *nbrs)
{
	int	i;
	int median;
	t_data	*node;

	i = 0;
	node = head_a;

	while (size_checkpoint_a > 3)
	{
		while (i < size_checkpoint_a)
		{
			if (node->number > median)
			{
				ft_pb(head_a, head_b);
				--size_checkpoint_a;
			}
			++i;
		}
		median = ft_calc_median(ft_bubble_sort(nbrs, size_checkpoint_a), size_checkpoint_a);
	}
}
