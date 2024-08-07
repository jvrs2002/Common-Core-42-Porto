/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joviribeiro <joviribeiro@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:38:37 by joao-vri          #+#    #+#             */
/*   Updated: 2024/08/07 22:01:21 by joviribeiro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pop(t_data **head);
int	ft_pop_bottom(t_data **head);
void	ft_push(t_data **head, int data);
void	ft_push_bottom(t_data **head, int data);

int	ft_pop(t_data **head)
{
	t_data	*first;
	t_data	*last;
	int	data;

	if (*head == NULL)
		return (-1);
	first = (*head);
	data = first->number;
	if (first->next == first)
		*head = NULL;
	else
	{
		last = first->prev;
		*head = first->next;
		(*head)->prev = last;
		last->next = *head;
	}
	free(first);
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

int	ft_pop_bottom(t_data **head)
{
	t_data	*last;
	t_data	*second_to_last;
	int	data;

	if (*head == NULL)
		return (-1);
	last = (*head)->prev;
	data = last->number;
	if (*head == last)
		*head = NULL;
	else
	{
		second_to_last = last->prev;
		(*head)->prev = second_to_last;
		second_to_last->next = *head;
	}
	free(last);
	return (data);
}

//FALTA FAZER O PUSH BOTTOM