/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:12:20 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/18 11:05:43 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_bubble_sort(int *nbrs, size_t size_checkpoint)
{
	size_t	i;
	int	swap;
	int	*nbrs_sorted;

	nbrs_sorted = (int *)malloc(sizeof(int) * size_checkpoint);
	if (!nbrs_sorted)
		return (NULL);
	memcpy(nbrs_sorted, nbrs, size_checkpoint * sizeof(int)); //MUDAR DPS PRA FT
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
		median = nbrs_sorted[i - 1] + nbrs_sorted[i];
		if (median % 2 != 0)
			++median;
		median /= 2;
	}
	else if (container_size % 2 != 0)
		median = nbrs_sorted[i];
	return (median);
}

void	ft_initial_push(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b, int *nbrs)
{
	size_t	i;
	int median;
	t_data	*node;

	i = 0;
	node = *head_a;
	nbrs = ft_bubble_sort(nbrs, *size_a);
	while (*size_a > 3)
	{
		median = ft_calc_median(nbrs, *size_a);
		printf("mediana: %i\n\n", median);
		while (i < *size_a)
		{
			if (node->number > median && *size_a > 3)
				ft_pb(head_a, head_b, size_a, size_b);
			else
				node = node->next;
			++i;
		}
	}
	median = ft_calc_median(nbrs, *size_a);
}