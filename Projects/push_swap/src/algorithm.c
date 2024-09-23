/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:12:20 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/23 14:14:16 by joao-vri         ###   ########.fr       */
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

int	*ft_median_pb(t_data **head_a, t_data **head_b, t_container *container, int *nbrs)
{
	int	median;
	size_t	i;
	size_t	*size_a;
	size_t	*size_b;

	size_a = &container->size_a_checkpoint;
	size_b = &container->size_b_checkpoint;
	i = 0;
	median = ft_calc_median(ft_bubble_sort(nbrs, *size_a), *size_a);
	printf("median: %i\n", median);
	if ((*container).size_a_checkpoint > 3)
	{
		while (i < *size_a)
		{
			if ((*head_a)->number < median)
				ft_pb(head_a, head_b, size_a, size_b);
			else
			{
				ft_ra(head_a, 1);
				++i;
			}
		}
	}
	if ((*container).size_a_checkpoint > 3)
		return (ft_copy_to_array(ft_bubble_sort(nbrs, *size_a), *head_a, size_a));
	else
		return (ft_copy_to_array(ft_bubble_sort(nbrs, *size_a), *head_b, size_b));
}

int	*ft_median_pa(t_data **head_a, t_data **head_b, t_container *container, int *nbrs)
{
	int	median;
	size_t	i;
	size_t	*size_a;
	size_t	*size_b;

	size_a = &container->size_a_checkpoint;
	size_b = &container->size_b_checkpoint;
	i = 0;
	median = ft_calc_median(ft_bubble_sort(nbrs, *size_b), *size_b);
	printf("median: %i\n", median);
	while (i < *size_b)
	{
		if ((*head_b)->number > median)
		{
			ft_pa(head_a, head_b, size_a, size_b);
			if ((*head_a)->number > (*head_a)->next->number)
				ft_sa(head_a, 1);
		}
		else
		{
			ft_rb(head_b, 1);
			++i;
		}
	}
	return (ft_copy_to_array(ft_bubble_sort(nbrs, *size_b), *head_b, size_b));
}

int	*ft_sort_a(t_data **head_a, size_t *size_a, int *nbrs)
{
	t_data	*node;
	t_data	*second_node;
	t_data	*third_node;

	if (*size_a < 2)
		return (NULL);
	node = (*head_a);
	second_node = node->next;
	if (*size_a == 3)
		third_node = second_node->next;
	else
		third_node = NULL;
	while ((*size_a == 2 && node->number > second_node->number) ||
		(*size_a == 3 && (node->number > second_node->number || second_node->number > third_node->number)))
	{
		if (*size_a == 3 && second_node->number > third_node->number)
			ft_ra(head_a, 1);
		if (node->number > second_node->number)
			ft_sa(head_a, 1);
		node = *head_a;
		second_node = node->next;
		if (*size_a == 3)
			third_node = second_node->next;
	}
	return (ft_copy_to_array(ft_bubble_sort(nbrs, *size_a), *head_a, size_a));
}
