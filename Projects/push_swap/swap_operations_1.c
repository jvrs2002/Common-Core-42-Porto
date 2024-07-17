/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:29:56 by joao-vri          #+#    #+#             */
/*   Updated: 2024/07/17 15:37:11 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data **head);
void	ft_sb(t_data **bottom);
void	ft_ss();

void	ft_sa(t_data **head)
{
	t_data *first;
	t_data *second;
	t_data *third;
	t_data *last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	third = second->next;
	last = first->prev;
	first->prev = second;
	first->next = third;
	second->next = first;
	second->prev = last;
	if (third != NULL)
		third->prev = first;
	if (last != NULL)
		last->next = second;
	*head = second;
}

void	ft_sb(t_data **bottom)
{
	t_data *first;
	t_data *second_to_last;
	t_data *third_to_last;
	t_data *last;

	if (*bottom == NULL || (*bottom)->next == NULL)
		return ;
	last = *bottom;
	second_to_last = last->prev;
	third_to_last = second->prev;
	first = last->next;
	first->prev = second_to_last;
	second_to_last->next = first;
	second_to_last->prev = last;
	last->next = second_to_last;
	last->prev = third_to_last;
	if (third_to_last != NULL)
		third_to_last->next = last;
	*bottom = second_to_last;
}


