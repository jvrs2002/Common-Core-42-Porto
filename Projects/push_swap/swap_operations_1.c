/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:29:56 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/24 16:44:11 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data **head);
void	ft_sb(t_data **bottom);
void	ft_ss(t_data **head, t_data **bottom);
void	ft_pa();
void	ft_pb();

void	ft_sa(t_data **head)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*last;

	if (*head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	third = second->next;
	last = first->prev;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	third->prev = first;
	*head = second;
}

void	ft_sb(t_data **bottom)
{
	t_data	*first;
	t_data	*second_to_last;
	t_data	*third_to_last;
	t_data	*last;

	if (*bottom == NULL || (*bottom)->next == *bottom)
		return ;
	last = *bottom;
	second_to_last = last->prev;
	third_to_last = second_to_last->prev;
	first = last->next;
	first->prev = second_to_last;
	second_to_last->next = first;
	second_to_last->prev = last;
	last->next = second_to_last;
	last->prev = third_to_last;
	third_to_last->next = last;
	*bottom = second_to_last;
}

void	ft_ss(t_data **head, t_data **bottom)
{
	ft_sa(head);
	ft_sb(bottom);
}
