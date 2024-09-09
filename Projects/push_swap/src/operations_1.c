/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:29:56 by joao-vri          #+#    #+#             */
/*   Updated: 2024/09/06 11:59:12 by joao-vri         ###   ########.fr       */
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
		write(1, "sa", 2);
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
		write(1, "sb", 2);
}

void	ft_ss(t_data **head_a, t_data **head_b)
{
	ft_sa(head_a, 0);
	ft_sb(head_b, 0);
	write(1, "ss", 2);
}

void	ft_pa(t_data **head_a, t_data **head_b)
{
	int	first_data_b;

	if(*head_b == NULL)
		return ;
	first_data_b = ft_pop(head_b);
	ft_push(head_a, first_data_b);
	write(1, "pa", 2);
}

void	ft_pb(t_data **head_a, t_data **head_b)
{
	int	first_data_a;

	if(*head_a == NULL)
		return ;
	first_data_a = ft_pop(head_a);
	ft_push(head_b, first_data_a);
	write(1, "pb", 2);
}