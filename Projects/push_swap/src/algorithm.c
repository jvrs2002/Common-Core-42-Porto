/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:12:20 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/11 18:37:16 by joao-vri         ###   ########.fr       */
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

int	ft_calc_median (int *nbrs, size_t container_size, size_t chunk_size)
{
	int	i;
	int	median;
	int	*nbrs_sorted;

	nbrs_sorted = ft_bubble_sort(nbrs, container_size);
	if (chunk_size == 0)
		return (0);
	i = chunk_size / 2;
	if (chunk_size % 2 == 0)
	{
		median = nbrs_sorted[i - 1] + nbrs_sorted[i];
		if (median % 2 != 0)
			++median;
		median /= 2;
	}
	else if (chunk_size % 2 != 0)
		median = nbrs_sorted[i];
	return (median);
}

void	ft_first_median_pb(t_data **head_a, t_data **head_b, t_container *container, int *nbrs)
{
	size_t	median_1;
	size_t	median_2;
	size_t	i;
	size_t	*size_a;
	size_t	*size_b;

	size_a = &container->size_a_checkpoint;
	size_b = &container->size_b_checkpoint;
	i = 0;
	nbrs = ft_copy_to_array(nbrs, *head_a, &container->size_a_checkpoint);
	median_1 = ft_calc_median(nbrs, *size_a, *size_a);
	median_2 = ft_calc_median(nbrs, *size_a, *(size_a) / 2);
	i = 0;
	while (i < *size_a)
	{
		if ((*head_a)->number < median_1)
		{
			ft_pb(head_a, head_b, size_a, size_b);
			if ((*head_b)->number < median_2)
			{
				ft_rb(head_b, 1);
				container->chunk_sizes[0] += 1;
			}
			else
				container->chunk_sizes[1] += 1;
		}
		else
		{
			if (*size_a > 3)
				ft_ra(head_a, 1);
			++i;
		}
	}
	while (container->size_a_checkpoint > 3)
		ft_median_pb(head_a, head_b, container, nbrs);
	ft_first_sort_a(head_a, size_a);
}

void	ft_median_pb(t_data **head_a, t_data **head_b, t_container *container, int *nbrs)
{
	size_t	median_1;
	size_t	median_2;
	size_t	i;
	size_t	n;
	size_t	*size_a;
	size_t	*size_b;

	container->chunk_count += 2;
	n = container->chunk_count;
	container->chunk_sizes[n] = 0;
	container->chunk_sizes[n + 1] = 0;
	size_a = &container->size_a_checkpoint;
	size_b = &container->size_b_checkpoint;
	i = 0;
	nbrs = ft_copy_to_array(nbrs, *head_a, &container->size_a_checkpoint);
	median_1 = ft_calc_median(nbrs, *size_a, *size_a);
	median_2 = ft_calc_median(nbrs, *size_a, *(size_a) / 2);
	while (i < *size_a)
	{
		if ((*head_a)->number < median_1)
		{
			ft_pb(head_a, head_b, size_a, size_b);
			if ((*head_b)->number > median_2)
			{
				ft_rb(head_b, 1);
				container->chunk_sizes[n + 1] += 1;
			}
			else
				container->chunk_sizes[n] += 1;
		}
		else
		{
			if (*size_a > 3)
				ft_ra(head_a, 1);
			++i;
		}
	}
	n = container->chunk_count;
	i = container->chunk_sizes[n + 1];
	while (i > 0)
	{
		ft_rrb(head_b, 1);
		i--;
	}
}

void	ft_median_pa(t_data **head_a, t_data **head_b, t_container *container, int *nbrs)
{
	int	median;
	size_t	i;
	size_t	*size_a;
	size_t	*size_b;

	size_a = &container->size_a_checkpoint;
	size_b = &container->size_b_checkpoint;
	nbrs = ft_copy_to_array(ft_bubble_sort(nbrs, container->size_b_checkpoint), *head_b, &container->size_b_checkpoint);
	median = ft_calc_median(nbrs, *size_b, *size_b);
	//printf("median: %i\n", median);
	while (i > 0)
	{
		if ((*head_b)->number > median)
			ft_pa(head_a, head_b, size_a, size_b);
		else
			ft_rb(head_b, 1);
		--i;
	}
	while (*size_b > 0 && *size_b <= 2)
		ft_pa(head_a, head_b, size_a, size_b);
}

void	ft_first_sort_a(t_data **head_a, size_t *size_a)
{
	t_data	*node;
	t_data	*second_node;
	t_data	*third_node;

	if (*size_a < 2 || *size_a > 3)
		return ;
	node = (*head_a);
	second_node = node->next;
	if (*size_a == 3)
		third_node = second_node->next;
	else
		third_node = NULL;
	while ((*size_a == 2 && node->number > second_node->number) ||
		(*size_a == 3 && (node->number > second_node->number || second_node->number > third_node->number)))
	{
		if (node->number > second_node->number)
			ft_sa(head_a, 1);
		if (*size_a == 3 && second_node->number > third_node->number)
			ft_rra(head_a, 1);
		node = *head_a;
		second_node = node->next;
		if (*size_a == 3)
			third_node = second_node->next;
	}
}

int	ft_check_sorted(int *nbrs, size_t size_a, t_data **head_a)
{
	size_t	i;
	int	*nbrs_sorted;

	nbrs = ft_copy_to_array(nbrs, *head_a, &size_a);
	if (size_a == 0)
		return (-1);
	i = size_a - 1;
	nbrs_sorted = ft_bubble_sort(nbrs, size_a);
	while (i > 0 && nbrs[i] == nbrs_sorted[i])
		--i;
	if (nbrs[i] == nbrs_sorted[i])
		return (-1);
	return (i + 1);
}
