/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:29:56 by joao-vri          #+#    #+#             */
/*   Updated: 2024/10/04 18:05:24 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_data **head_a, int flag)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*last;

	if (*head_a == NULL || (*head_a)->next == *head_a)
		return ;
	first = *head_a;
	second = first->next;
	third = second->next;
	last = first->prev;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	third->prev = first;
	*head_a = second;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_data **head_b, int flag)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*last;

	if (*head_b == NULL || (*head_b)->next == *head_b)
		return ;
	first = *head_b;
	second = first->next;
	third = second->next;
	last = first->prev;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	third->prev = first;
	*head_b = second;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_data **head_a, t_data **head_b)
{
	ft_sa(head_a, 0);
	ft_sb(head_b, 0);
	write(1, "ss\n", 3);
}

void	ft_pa(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b)
{
	int	first_data_b;

	t_data *first_node;
	t_data *second_node;

	first_node = (*head_a);
	second_node = first_node->next;

	if(*head_b == NULL)
		return ;
	first_data_b = ft_pop(head_b);
	ft_push(head_a, first_data_b);
	++(*size_a);
	--(*size_b);
	if (first_node->number > second_node->number)
		ft_sa(head_a, 1);
	write(1, "pa\n", 3);
}

void	ft_pb(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b)
{
	int	first_data_a;

	if(*head_a == NULL)
		return ;
	first_data_a = ft_pop(head_a);
	ft_push(head_b, first_data_a);
	--(*size_a);
	++(*size_b);
	write(1, "pb\n", 3);
}
