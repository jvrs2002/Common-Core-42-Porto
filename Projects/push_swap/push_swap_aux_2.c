/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:38:37 by joao-vri          #+#    #+#             */
/*   Updated: 2024/08/06 18:06:24 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_data **head, int data);
int	ft_pop(t_data **head);

int	ft_pop(t_data **head)
{
	t_data	*temp;
	t_data	*last;
	int	data;

	if (*head == NULL)
		return (-1);
	temp = *head;
	data = temp->number;
	if ((*head)->next == *head)
		*head = NULL;
	else
	{
		last = (*head)->prev;
		*head = (*head)->next;
		(*head)->prev = last;
		last->next = *head;
	}
	free(temp);
	return (data);
}

void	ft_push(t_data **head, int data)
{
	t_data	*new_node;
	t_data	*last;

	new_node = (t_data*)malloc(sizeof(t_data));
	new_node->number = data;
	if(*head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
	}
	else
	{
		last = (*head)->prev;
		new_node->next = *head;
		new_node->prev = last;
		last->next = new_node;
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}
